#include<bits/stdc++.h>
#define ll long long
using namespace std ;
const int N = 5e5 + 7 ;
const int M = 3e5 + 7 ;
int n , m ;
bool f [ N ] ;
int a [ N ] , t [ N ] , cf [ N ] ;
vector < int > v [ M ] , g ;
bool cmp ( int _x , int _y ) {
	return v [ _x ] [ 1 ] < v [ _y ] [ 1 ] ;
}
int main () {
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a [ i ] ;
		v [ a [ i ] ] . push_back ( i ) ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		if ( ! f [ a [ i ] ] && v [ a [ i ] ] . size () > 1 ) {
			f [ a [ i ] ] = 1 ;
			g . push_back ( a [ i ] ) ;
		}
	}
	sort ( g . begin () , g . end () , cmp ) ;
	for ( int st = 1 ; st <= n ; st ++ ) {
		int j = v [ g [ 0 ] ] [ 0 ] ;
		int k = 1 ;
		while ( j <= n && k < g . size () ) {
			cf [ v [ a [ j ] ] [ v [ a [ j ] ] . size () - 1 ] ] ++ ;
			cf [ j + 1 ] -- ;
			int l = j , r = v [ a [ j ] ] [ v [ a [ j ] ] . size () - 1 ] ;
			while ( l <= j && j <= r && k < g . size () ) {
				j = v [ g [ k ++ ] ] [ 0 ] ;
			}
		}
		v [ a [ st ] ] . erase ( v [ a [ st ] ] . begin () ) ;
		if ( v [ a [ st ] ] . size () == 1 ) {
			for ( int p = g . size () - 1 ; p >= 0 ; p -- ) {
				if ( g [ p ] == a [ st ] ) {
					g . erase ( g . begin () + p ) ;
					break ;
				}
			}
		}
		sort ( g . begin () , g . end () , cmp ) ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		cf [ i ] += cf [ i - 1 ] ;
		t [ a [ i ] ] += cf [ i ] + i ;
	}
	for ( int i = 1 ; i <= m ; i ++ ) cout << t [ i ] << ' ' ;
	return 0;
}
