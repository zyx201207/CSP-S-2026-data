#include <bits/stdc++.h>
#define ll long long
using namespace std ;
string a , b , c , d ;
int main() {
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
//	freopen ( "text.in" , "r" , stdin ) ;
//	freopen ( "my.out" , "w" , stdout ) ;
	ios::sync_with_stdio ( false ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> a >> b >> c >> d ;
	if ( a == c ) {
		cout << 1 ;
		if ( b [0] == d [0] && b [1] == d [1] ) {
			cout << 1 ;
			int x = b [2] - 'A' , y = d [2] - 'A' ;
			if ( ( x <= 2 && y <= 2 ) || ( x >= 3 && y >= 3 ) ) {
				cout << 1 ;
				if ( x <= 2 && y <= 2 ) {
					if ( ( x == 1 && y == 2 ) || ( x == 0 || y == 1 ) || ( y == 0 && x == 1 ) || ( y == 1 && x == 2 ) )
						cout << 1 ;
					else
						cout << 0 ;
				}
				else
					cout << 1 ;
			}
			else
				cout << "00" ;
		}
		else
			cout << "000" ;
	}
	else {
		cout << "0000" ;
	}
	return 0 ;
}
