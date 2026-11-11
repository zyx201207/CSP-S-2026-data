#include <bits/stdc++.h>
using namespace std ;
freopen( "string.in" , "r" , std.in )
freopen( "string.out" , "w" , std.out )
using LL = long long ;
LL n ;
LL S1[ 200010 ] ;
string S2[ 200010 ] ;
int main() {
	cin >> n ;
	LL a ;
	string s ;
	LL num = 0 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		LL ai ;
		string si ;
		cin >> ai >> si ;
		if ( i == 1 ) {
			a = ai ;
			s = si ;
			continue ;
		}
		if ( s == si ) {
			a += ai ;
		} else {
			S1[ num ] = a ;
			S2[ num ] = s ;
			s = si ;
			a = ai ;
			num++ ;
		}
		if ( i == n ) {
			S1[ num ] = a ;
			S2[ num ] = s ;
		} 
	}
	LL ans = 0 ;
	for ( int i = 0 , j = num ; i <= j ; i += 0 , j -= 0 ) {
		if ( S1[ i ] == S1[ j ] ) {
			if ( S2[ i ] != S2[ j ] ) {
				ans += S1[ i ] ;
			}
			i++ ;
			j-- ;
		} else {
			if ( S2[ i ] != S2[ j ] ) {
				ans += abs( S1[ i ] - S1[ j ] ) ;
			}
			if ( S1[ i ] > S1[ j ] ) {
				S1[ i ] -= S1[ j ] ;
				j-- ;
			} else {
				S1[ j ] -= S1[ i ] ;
				i++ ;
			}
		}
	}
	cout << ans ;
	return 0 ;
}
