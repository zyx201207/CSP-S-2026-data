#include <bits/stdc++.h>
using namespace std ;
long long n , a [ 200005 ] , b [ 200005 ] , sumn , pos_mid , t ;
char c [ 200005 ] , d [ 200005 ] ;
int method ( ) {
	long long ans = 0 , j = t , need = 0 ;
	for ( int i = 1 ; i <= pos_mid ; i++ ) {
		if ( d [ i ] == d [ j ] && b [ i ] == b [ j ] ) {
			j-- ;
			continue ;
		} else if ( d [ i ] == d [ j ] ) {
			long long z = abs ( b [ i ] - b [ j ] ) ;
			need = z ;
			if ( b [ i ] > b [ j ] ) b [ j - 1 ] -= z ;
			else b [ i + 1 ] -= z ;
			ans += z ;
			j-- ;
		} else {
			long long zz = max ( b [ i ] , b [ j ] ) ;
			need = abs ( b [ i ] - b [ j ] ) ;
			if ( b [ i ] > b [ j ] ) b [ j - 1 ] -= need ;
			else b [ i + 1 ] -= need ;
			j-- ;
			ans += zz ;
		} 
	} return ans ;
}
int main ( ) {
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] >> c [ i ] ;
	long long aa = 0 ;
	char cc = ' ' ; 
	for ( int i = 1 ; i <= n ; i++ ) {
		sumn += a [ i ] ;
		if ( c [ i ] == cc ) aa += a [ i ] ;
		else {
			b [ t ] = aa ;
			d [ t ] = cc ;
			t++ ;
			aa = a [ i ] ;
			cc = c [ i ] ;
		}
	}
	b [ t ] = aa , d [ t ] = cc ;
	if ( t == 1 ) {
		cout << 0 ;
		return 0 ;
	} aa = 0 ;
	pos_mid = t / 2 ;
	if ( t % 2 == 1 ) pos_mid++ ;
	cout << method ( ) << endl ;
}

