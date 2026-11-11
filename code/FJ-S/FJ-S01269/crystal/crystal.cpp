#include <bits/stdc++.h>
using namespace std ;
int n , m ;
long long a [ 512345 ] ;
long long qsum [ 512345 ] ;
long long  l , r ;
bool check ( int mid ) {
	for ( int i = mid ; i <= n ; i ++ ) {
		if ( a [ i ] * mid - ( qsum [ i + 1 ] - qsum [ i - mid ] ) <= m ) {
			return 1 ;
		} 
	}
	return 0 ;
}
int main ( ) {
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a [ i ] ;
		qsum [ i ] = qsum [ i - 1 ] + a [ i ] ;
	}
	long long ans = 0 ;
	l = 1 , r = n ;
	while ( l < r ) {
		long long mid = l + ( r - l ) / 2 ;
		if ( check ( mid ) ) {
			l = mid + 1 ;
			ans = mid ;
		} else {
			r = mid - 1 ;
		}
	}
	cout << ans ;	
	return 0 ;
}
