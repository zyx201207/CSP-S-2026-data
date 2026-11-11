#include <bits/stdc++.h>
using namespace std ;
long long c , n , d , pos [ 2000005 ] , t , diff [ 2000005 ] , diff_sum [ 2000005 ] , ans ;
int main ( ) {
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	cin >> c >> t ;
	while ( t-- ) {
		cin >> n >> d ;
		for ( int i = 1 ; i <= n ; i++ ) cin >> pos [ i ] ;
		for ( int i = 1 ; i < n ; i++ ) diff [ i ] = pos [ i + 1 ] - pos [ i ] ;
		for ( int i = 1 ; i < n ; i++ ) diff_sum [ i ] = diff_sum [ i - 1 ] + diff [ i ] ;
		if ( c == 11 || c == 12 ) {
			int dis = 2 * d - 1 ;
			if ( dis % diff [ 1 ] != 0 ) cout << 0 << endl ;
			else {
				int tt = dis / diff [ 1 ] ;
				cout << n - tt << endl ;
			}
		} else {
			for ( int i = 1 ; i <= n ; i++ ) for ( int j = i + 1 ; j <= n ; j++ ) {
				int tt = 0 ;
				if ( pos [ j ] - pos [ i ] == d ) continue ;
				for ( int k = i + 1 ; k < j ; k++ ) if ( pos [ k ] - pos [ i ] <= d && pos [ j ] - pos [ k ] <= d ) {
					tt++ ;
					//cout << pos [ i ] << ' ' << pos [ k ] << ' ' << pos [ j ] << ' ' << tt << endl ;
				}   
				if ( tt == 2 ) ans++ ;
			}
			cout << ans << endl ;
		}
		memset ( pos , 0 , sizeof ( pos ) ) ;
		memset ( diff , 0 , sizeof ( d ) ) ;
		memset ( diff_sum , 0 , sizeof ( diff_sum ) ) ;
		ans = 0 ;
	}
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

11 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 0 1

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
