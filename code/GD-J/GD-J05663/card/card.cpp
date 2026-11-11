#include <bits/stdc++.h>
using namespace std ;

int n , m , a [200001] , ans [200001] ;
int ax [200001] , s [200001] ;
bool bx [200001] ;

int main () {
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	scanf ( "%d%d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ )
		scanf ( "%d" , &a [i] ) ;
	for ( int i = 1 ; i <= n ; i++ ){
		memset ( ax , 0 , sizeof ( ax ) ) ;
		memset ( bx , 0 , sizeof ( bx ) ) ;
		memset ( s , 0 , sizeof ( s ) ) ;
		int x = i , y = 0 ;
		while ( x <= n ){
			int z = a [x] ;
			if ( !bx [z] ){
				bx [z] = 1 ;
				s [++y] = a [x] ;
				ax [z] = y ;
			}else{
				for ( int j = ax [z] + 1 ; j <= y ; j++ )
					bx [ s [j] ] = 0 ;
				y = ax [z] ;
			}
			x++ ;
		}
		for ( int j = 1 ; j <= y ; j++ )
			ans [ s [j] ]++ ;
	}
	for ( int i = 1 ; i <= m ; i++ )
		printf ( "%d " , ans [i] ) ;
}
