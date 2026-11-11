#include <bits/stdc++.h>
#define ll long long
using namespace std ;
string s ;
int n ;
int main() {
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
//	freopen ( "text.in" , "r" , stdin ) ;
//	freopen ( "my.out" , "w" , stdout ) ;
	ios::sync_with_stdio ( false ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; ++i ) {
		int x ;
		string ch ;
		cin >> x >> ch ;
		for ( int j = 1 ; j <= x ; ++j ) {
			s += ch ;
		}
	}
	ll len = s.size() ;
	ll ans = 0 ;
	for ( int i = 0 ; i <= ( len - 1 ) / 2 ; ++i ) {
		if ( s [i] != s [ len - i - 1 ] )
			++ans ;
	}
	cout << ans ;
	return 0 ;
}
