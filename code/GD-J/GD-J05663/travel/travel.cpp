#include <bits/stdc++.h>
using namespace std ;

char c1 [3] , s1 [4] , c2 [3] , s2 [4] ;

int main () {
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
	scanf ( "%c%c " , &c1 [1] , &c1 [2] ) ;
	scanf ( "%c%c%c " , &s1 [1] , &s1 [2] , &s1 [3] ) ;
	scanf ( "%c%c " , &c2 [1] , &c2 [2] ) ;
	scanf ( "%c%c%c" , &s2 [1] , &s2 [2] , &s2 [3] ) ;
	if ( c1 [1] == c2 [1] && c1 [2] == c2 [2] ){
		printf ( "1" ) ;
		if ( s1 [1] == s2 [1] && s1 [2] == s2 [2] ){
			printf ( "1" ) ;
			int x = 0 , y = 0 ;
			if ( s1 [3] == 'A' || s1 [3] == 'B' || s1 [3] == 'C' )
				x = 1 ;
			if ( s1 [3] == 'D' || s1 [3] == 'F' )
				x = 2 ;
			if ( s2 [3] == 'A' || s2 [3] == 'B' || s2 [3] == 'C' )
				y = 1 ;
			if ( s2 [3] == 'D' || s2 [3] == 'F' )
				y = 2 ;
			if ( x == y ){
				printf ( "1" ) ;
				if ( x == 1 ){
					if ( s1 [3] + 1 == s2 [3] || s2 [3] + 1 == s1 [3] )
						printf ( "1" ) ;
					else 
						printf ( "0" ) ;
				}
				if ( x == 2 ){
					if ( ( s1 [3] == 'D' && s2 [3] == 'F' ) || ( s1 [3] == 'F' && s2 [3] == 'D' ) )
						printf ( "1" ) ;
					else 
						printf ( "0" ) ;
				}
			}else
				printf ( "00" ) ;
		}else {
			printf ( "000" ) ;
		}
	}else {
		printf ( "0000" ) ;
	}
}
