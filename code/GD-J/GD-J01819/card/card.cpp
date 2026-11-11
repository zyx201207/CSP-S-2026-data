#include <map>
#include <iostream>
using namespace std ;
map < int , int > mp , mp2 ;
int n , m , a [ 500010 ] , t [ 500010 ] ;
int main()
{
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		scanf ( "%d" , &a [ i ] ) ;
	}
	for ( int i = n ; i >= 1 ; i -- )
	{
		if ( mp [ a [ i ] ] )
		{
			t [ i ] = mp [ a [ i ] ] ;
		}
		mp [ a [ i ] ] = i ;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		int j = i , ans [ 500010 ] = { } ;
		while ( j <= n )
		{
			if ( t [ j ] ) j = t [ j ] ;
			else
			{
				ans [ ++ ans [ 0 ] ] = a [ j ] ;
				j ++ ;
			}
		}
		for ( int i = 1 ; i <= ans [ 0 ] ; i ++ )
		{
			mp2 [ ans [ i ] ] ++ ;
		}
	}
	for ( int i = 1 ; i <= m ; i ++ ) printf ( "%d " , mp2 [ i ] ) ;
	return 0 ;
}
