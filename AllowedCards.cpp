// AllowedCards.cpp: implementation of the CAllowedCards class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AllowedCards.h"
#include <time.h>



// ---------------------------------------------------------
// Konstruktor
//
CAllowedCards::CAllowedCards() 
{ 
	m_nCards = 0;
}


// ---------------------------------------------------------
// Dodanie kart do kart mo�liwych do po�o�enia
// w puzzlach
//
void 
CAllowedCards::AddCard(
	short a_nInHand		//WE kt�ra w r�ce
	)
{
	if (a_nInHand < 0)
	{
		return;
	}
	m_arrCardsPoints[m_nCards].SetCardPoints(a_nInHand);
	m_nCards++;

}


// ---------------------------------------------------------
// Posortowanie wybranych kart
//
void 
CAllowedCards::Sort()
{
	// nie ma co sortowa�?
	if ((m_nCards <= 1))
	{
		return;
	}

    srand((unsigned)time(NULL)); // inicjalizacja generatora

	int l_iAt;
	// rozsortowanie tablicy 52 liczb
	for (l_iAt = 0; l_iAt < 10; l_iAt++)
	{
		int l_iFirst = rand() * m_nCards / RAND_MAX - 1;
		int l_iSecond = rand() * m_nCards / RAND_MAX - 1;
		if (l_iFirst < 0)
			l_iFirst = 0;
		if (l_iFirst > 7)
			l_iFirst = 7;
		if (l_iSecond < 0)
			l_iSecond = 0;
		if (l_iSecond > 7)
			l_iSecond = 7;
		short l_nCopyBuf = m_arrCardsPoints[l_iFirst].GetCard();
		m_arrCardsPoints[l_iFirst].SetCardPoints(m_arrCardsPoints[l_iSecond].GetCard());
		m_arrCardsPoints[l_iSecond].SetCardPoints(l_nCopyBuf);
	}

}


// ---------------------------------------------------------
// Zwraca ilo�� punkt�w dla pozycji
//
short	//WY ilo�� punkt�w
CAllowedCards::GetPoints(
	short a_nAt		//WE pozycja
	) const
{
	return m_arrCardsPoints[a_nAt].GetPoints();
}


// ---------------------------------------------------------
// Pobiera numer karty
//
short	//WE ilo�� dozwolonych kart
CAllowedCards::GetAllowedCount() const
{
	return m_nCards;
}


// ---------------------------------------------------------
// Zwraca dozwolona kart�
//
short	//WY numer w r�ce dozwolonej karty
CAllowedCards::GetCard(
	short a_nPos	//WE kt�ra dozwolona karta
	) const
{
	ASSERT(a_nPos >= 0);
	ASSERT(a_nPos < m_nCards);
	return m_arrCardsPoints[a_nPos].GetCard();
}


// ---------------------------------------------------------
// Ustawia ilo�� punkt�w dla karty
//
void 
CAllowedCards::SetPoints(
	short a_nAt,		//WE karta
	short a_nPoints		//WE punkt�w
	)
{
	m_arrCardsPoints[a_nAt].SetPoints(a_nPoints);
}


// ---------------------------------------------------------
// Zwraca ilo�� punkt�w
//
short	//WY ilo�� punkt�w
CAllowedCards::CCardsPoints::GetPoints() const
{
	return m_nPoints;
}


// ---------------------------------------------------------
// Pobiera numer karty
//
short	//WY numer karty
CAllowedCards::CCardsPoints::GetCard() const
{
	return m_nInHand;
}


// ---------------------------------------------------------
// Ustawienie punktacji
//
void 
CAllowedCards::CCardsPoints::SetPoints(
	short a_nPoints		//WE ilo�� punkt�w
	)
{
	m_nPoints = a_nPoints;
}


// ---------------------------------------------------------
// Ustawienie dost�pnej karty
//
void 
CAllowedCards::CCardsPoints::SetCardPoints(
	short a_nInHand,	//WE karta w r�ku
	short a_nPoints		//WE ilo�� punkt�w
	)
{
	m_nInHand = a_nInHand;
	m_nPoints = a_nPoints;
}