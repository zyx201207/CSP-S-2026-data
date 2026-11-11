#include<bits/stdc++.h>
using namespace std ;
int n ;
char c [ 212345 ] ;
long long a [ 212345 ] ;
long long qsum [ 212345 ] ;
long long hsum [ 212345 ] ;
int l , r ;
long long ans ;
char str [ 1123456 ] ;
int main ( ) {
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a [ i ] >> c [ i ] ;
		qsum [ i ] = qsum [ i - 1 ] + a [ i ] ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		hsum [ i ] = hsum [ i + 1 ] + a [ i ] ;
	}
	if ( qsum [ n ] <= 1e6 ) {
		int pos = 0 ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			for ( int j = 1 ; j <= a [ i ] ; j ++ ) str [ ++ pos ] = c [ i ] ;
		}
		for ( int i = 1 , j = qsum [ n ] ; i < j ; i ++ , j -- ) {
			if ( str [ i ] != str [ j ] ) {
				ans ++ ;
			}
		}
		cout << ans ;
	} else {
		l = 1 ; 
		r = n ;
		while ( l <= r ) {
			if ( qsum [ l ] > hsum [ r ] ) {
				r -- ;
				if ( c [ r ] != c [ l ] ) {
					ans += abs ( qsum [ l ] - hsum [ r ] ) ;
				}
			} else {
				l ++ ;
				if ( c [ r ] != c [ l ] ) {
					ans += abs ( qsum [ l ] - hsum [ r ] ) ;
				}
			}
		}
		cout << ans ;
	}
	return 0 ; 
}
