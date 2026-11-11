#include <bits/stdc++.h>
using namespace std ;
long long n , m , a [ 500005 ] , vis [ 300005 ] , query [ 500005 ] ;
int main ( ) {
	freopen ( "card.in" , "r" , stdin ) ;
	freopen ( "card.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] ;
	for ( int i = 1 ; i <= n ; i++ ) {
		int pos_i [ 500005 ] = { 0 } , t = 1 ;
		bool vis_j [ 500005 ] = { false } , vis_i [ 500005 ] = { false } ;
		for ( int j = i ; j <= n ; j++ ) {
			bool f = false , pos = 0 ;
			for ( int k = 1 ; k <= t ; k++ ) {
				if ( query [ k ] == a [ j ] ) {
					//cout << query [ k ] << ' ' << a [ j ] << endl ;
					f = true ;
					pos = k ;
					break ;
				}
			}//cout << pos << ' ' << f << ' ' << t << ' ' << j << endl ;
			if ( f ) {
				for ( int k = pos + 1 ; k <= t ; k++ ) query [ k ] = 0 ;
				t = pos + 1 ;
			} else {
				query [ t ] = a [ j ] ;
				t++ ;
			}
			/*
			if ( ! vis_i [ a [ j ] ] ) {
				query [ t ] = a [ j ] ;
				pos_i [ a [ j ] ] == t ;
				vis_i [ a [ j ] ] == true ;
				t++ ;
			} else {
				for ( int k = pos_i [ a [ j ] ] + 1 ; k <= t ; k++ ) query [ k ] = 0 ;
				t = pos_i [ a [ j ] ] + 1 ;
			}
			/*
			if ( a [ j ] != i ) {
				query [ t ] = a [ j ] ;
				t++ ;
			} else {
				if ( vis_i == 0 ) {
					query [ t ] = a [ j ] ;
					pos_i = t ;
					vis_i++ ;
					t++ ;
				} else {
					for ( int k = pos_i + 1 ; k <= t ; k++ ) query [ k ] = 0 ;
					t = pos_i + 1 ;
				}
			}
			*/
			//for ( int k = 1 ; k <= t ; k++ ) cout << query [ k ] << ' ' ;
			//cout << endl ;
		} 
		for ( int k = 1 ; k <= t ; k++ ) vis_j [ query [ k ] ] = true ;
		for ( int k = 1 ; k <= m ; k++ ) vis [ k ] += vis_j [ k ] ;
		memset ( query , 0 , sizeof ( query ) ) ;
		memset ( vis_j , false , sizeof ( vis_j ) ) ;
	} for ( int i = 1 ; i <= m ; i++ ) cout << vis [ i ] << ' ' ;
}
