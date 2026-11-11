#include<bits/stdc++.h>
#define ll long long
using namespace std ;
string c1 , s1 , c2 , s2 ;
map < char , bool > fl ;
map < char , int > id ;
int main () {
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2 ;
	if ( c1 != c2 ) {
		cout << "0000" ;
		return 0 ;
	} else {
		cout << 1 ;	
	}
	fl [ 'A' ] = 1 , fl [ 'B' ] = 1 , fl [ 'C' ] = 1 ;
	fl [ 'D' ] = 0 , fl [ 'F' ] = 0 ;
	id [ 'A' ] = 1 , id [ 'B' ] = 2 , id [ 'C' ] = 3 ;
	id [ 'D' ] = 5 , id [ 'F' ] = 6 ;
	if ( s1 [ 0 ] == s2 [ 0 ] && s1 [ 1 ] == s2 [ 1 ] ) {
		cout << 1 ;
		if ( fl [ s1 [ 2 ] ] == fl [ s2 [ 2 ] ] ) {
			cout << 1 ;
			if ( abs ( id [ s1 [ 2 ] ] - id [ s2 [ 2 ] ] ) == 1 ) {
				cout << 1 ;
			} else {
				cout << 0 ;
			}
		} else {
			cout << "00" ;
		}
	} else {
		cout << "000" ;
	}
	return 0;
}
