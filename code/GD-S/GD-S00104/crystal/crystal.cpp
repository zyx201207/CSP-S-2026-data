#include <bits/stdc++.h>
using namespace std ;
long long n , m , a [ 500005 ] , d [ 500005 ] , diff_sum [ 500005 ] ;
int ans ;
int main ( ) {
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] ;
	sort ( a + 1 , a + n + 1 ) ;
	for ( int i = 1 ; i < n ; i++ ) d [ i ] = a [ i + 1 ] - a [ i ] ;
	//for ( int i = 1 ; i < n ; i++ ) cout << d [ i ] << ' ' ;
	//cout << endl ;
	for ( int i = 1 ; i < n ; i++ ) diff_sum [ i ] = diff_sum [ i - 1 ] + d [ i ] ;
	//for ( int i = 1 ; i < n ; i++ ) cout << diff_sum [ i ] << ' ' ;
	//cout << endl ;
	//cout << m << endl ;
	for ( int i = 1 ; i < n ; i++ ) {
		int j = 0 ;
		while ( true ) {
			//cout << diff_sum [ i + j ] << ' ' << diff_sum [ i - 1 ] << ' ' << diff_sum [ i + j ] - diff_sum [ i - 1 ] << endl ;
			if ( diff_sum [ i + j ] - diff_sum [ i - 1 ] > m || diff_sum [ i + j ] - diff_sum [ i - 1 ] < 0 || j == n ) break ;
			else j++ ;
		}
		ans = max ( ans , j + 1 ) ;
	} cout << ans ;
}
