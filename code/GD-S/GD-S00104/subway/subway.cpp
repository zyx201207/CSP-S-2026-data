#include <bits/stdc++.h>
using namespace std ;
int c , n , m , d , q , w [ 500005 ] , k [ 505 ] , a [ 505 ] [ 50005 ] , t [ 505 ] [ 50005 ] , ans , l , r ;
vector <int> gt [ 505 ] ;
vector <int> tn [ 505 ] ;
bool vis [ 5005 ] ;
int dfs ( int s_pos , int e_pos , int tt , int last ) {
	int mina = 1e7 ;
	if ( s_pos == e_pos ) return tt ;
	for ( int i = 0 ; i < gt [ s_pos ].size ( ) ; i++ ) {
		if ( vis [ gt [ s_pos ] [ i ] ] ) continue ;
		else {
			vis [ gt [ s_pos ] [ i ] ] = true ;
			mina = min ( dfs ( gt [ s_pos ] [ i ] , e_pos , tt + tn [ s_pos ] [ i ] , s_pos ) , mina ) ;
			vis [ gt [ s_pos ] [ i ] ] = false ;
		}
	} return mina ;
}
int main ( ) {
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	cin >> c >> n >> m >> d >> q ;
	for ( int i = 1 ; i <= m ; i++ ) cin >> w [ i ] ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> k [ i ] ;
		for ( int j = 1 ; j <= k [ i ] ; j++ ) cin >> a [ i ] [ j ] >> t [ i ] [ j ] ; 
		for ( int x = 1 ; x <= k [ i ] ; x++ ) for ( int y = x + 1 ; y <= k [ i ] ; y++ ) {
			gt [ a [ i ] [ x ] ].push_back ( a [ i ] [ y ] ) ;
			gt [ a [ i ] [ y ] ].push_back ( a [ i ] [ x ] ) ;
			tn [ a [ i ] [ x ] ].push_back ( t [ i ] [ x ] + t [ i ] [ y ] ) ;
			tn [ a [ i ] [ y ] ].push_back ( t [ i ] [ x ] + t [ i ] [ y ] ) ;
		}
	} 
	/*
	for ( int i = 1 ; i <= m ; i++ ) {
		cout << i << ": " ;
		for ( int j = 0 ; j < gt [ i ].size ( ) ; j++ ) cout << gt [ i ] [ j ] << ' ' << tn [ i ] [ j ] << ' ' ;
		cout << endl ;
	}
	*/
	for ( int i = 1 ; i <= q ; i++ ) {
		cin >> l >> r ;
		ans = dfs ( l , r , 0 , 0 ) ;
		//cout << ans << endl ;
		ans += w [ l ] + w [ r ] ;
		cout << ans << endl ;
	}
	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
