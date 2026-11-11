#include <bits/stdc++.h>
using namespace std ;
int acar , bcar ;
string aseat , bseat ;
int main ( ) {
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
	cin >> acar >> aseat >> bcar >> bseat ;
	if ( acar == bcar ) cout << 1 ;
	else cout << "0000" ;
	return 0 ;
	if ( aseat.substr ( 0 , 2 ) == bseat.substr ( 0 , 2 ) ) {
		cout << 1 ;
		if ( ( aseat [ 2 ] == 'A' || aseat [ 2 ] == 'B' || aseat [ 2 ] == 'C' ) && ( bseat [ 2 ] == 'D' || bseat [ 2 ] == 'F' ) || ( bseat [ 2 ] == 'A' || bseat [ 2 ] == 'B' || bseat [ 2 ] == 'C' ) && ( aseat [ 2 ] == 'D' || aseat [ 2 ] == 'F' ) ) cout << "00" ;
		else if ( aseat [ 2 ] == 'D' && bseat [ 2 ] == 'F' || aseat [ 2 ] == 'F' && bseat [ 2 ] == 'D' ) cout << "11" ;
		else {
			if ( aseat [ 2 ] + 1 == bseat [ 2 ] || bseat [ 2 ] + 1 == aseat [ 2 ] ) cout << "11" ;
			else cout << "10" ;
		}
	} else cout << "000" ;
}
