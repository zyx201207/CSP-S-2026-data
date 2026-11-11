#include <bits/stdc++.h>
using namespace std ;

int n , a [200001] ;
char c [200001] ; 
long long ans ;

int main () {
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ )
		scanf ( "%d %c" , &a [i] , &c [i] ) ;
	if ( n == 1 )
		printf ( "0" ) ;
	int l = 1 , r = n ;
	while ( l < r ){
		int x = min ( a [l] , a [r] ) ;
		a [l] -= x , a [r] -= x ;
		if ( c [l] != c [r] )
			ans += x ;
		if ( a [l] == 0 )
			l++ ;
		if ( a [r] == 0 )
			r-- ;
	}
	printf ( "%lld" , ans ) ;
}
