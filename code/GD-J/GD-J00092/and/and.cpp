#include <bits/stdc++.h>'
using namespace std ;
long long ans , n , m , a [ 200005 ] , b [ 200005 ] , c [ 200005 ] ;
int main ( ) {
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] ;
	sort ( a + 1 , a + n + 1 ) ;
	for ( int i = 1 ; i <= m ; i++ ) for ( int j = 1 ; j <= n - i ; j++ ) a [ j ] &= a [ j + 1 ] ;
	for ( int i = 1 ; i <= n - m + 1 ; i++ ) ans = max ( ans , a [ i ] ) ;
	cout << ans ;
}
