#include <bits/stdc++.h>
using namespace std ;
freopen( "card.in" , "r" , std.in )
freopen( "card.out" , "w" , std.out )
int a[ 500010 ] , b[ 500010 ] , c[ 300010 ] ;
bool tf[ 500010 ] ;
int main() {
	int n , m ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a[ i ] ;
	}
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			tf[ j ] = false ;
		}
		int num = 0 ;
		for ( int j = i ; j <= n ; j++ ) {
			if ( tf[ a[ j ] ] ) {
				while( b[ num ] != a[ j ] ) {
					num-- ;
					tf[ b[ num ] ] = false ;
				}
				b[ num ] = a[ j ] ;
				num++ ;
				tf[ a[ j ] ] = true ;
			} else {
				b[ num ] = a[ j ] ;
				num++ ;
				tf[ a[ j ] ] = true ;
			}
		}
		for ( int j = 0 ; j < num ; j++ ) {
			c[ b[ j ] ]++ ;
		}
	}
	for ( int i = 1 ; i <= m ; i++ ) {
		cout << c[ i ] << " " ;
	}
	return 0 ;
}
