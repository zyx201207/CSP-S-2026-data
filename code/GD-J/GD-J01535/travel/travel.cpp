#include<bits/stdc++.h>
using namespace std;
string a , b , c , d;
int main() {
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout );
	cin >> a >> b >> c >> d;
	if ( a == c)  {
		cout << 1 ;
		if ( b[0] == d[0] && b[1] == d[1] ) {
			cout << 1 ;
			int k = (b[2] == 'D' || b[2] == 'F' ) ? 1 : 0;
			int o = (d[2] == 'D' || d[2] == 'F' ) ? 1 : 0;
			if ( ( k && o )||(!k && !o ) ) {
				cout << 1 ;
				if ( (int(d[2] - 1) == b[2] ) || (int(b[2] - 1) == d[2] )) {
					cout << 1 ; 
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
