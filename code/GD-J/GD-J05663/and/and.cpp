#include <bits/stdc++.h>
using namespace std ;

int n , m , a [200001] ;

int main () {
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	scanf ( "%d%d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ )
		scanf ( "%d" , &a [i] ) ;
	if ( m == 1 ){
		sort ( a + 1 , a + n + 1 ) ;
		printf ( "%d" , a [n] ) ;
	}
	if ( m == 2 ){
		int ma = 0 ;
		for ( int i = 1 ; i <= n ; i++ )
			for ( int j = i + 1 ; j <= n ; j++ )
				if ( a [i] & a [j] > ma )
					ma = a [i] & a [j] ;
		printf ( "%d" , ma ) ;
	}
}
