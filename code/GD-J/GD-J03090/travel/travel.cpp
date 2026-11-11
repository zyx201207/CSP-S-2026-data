#include <bits/stdc++.h>
using namespace std ;
freopen( "travel.in" , "r" , std.in )
freopen( "travel.out" , "w" , std.out )
int main() {
	string c1 , c2 , s1 , s2 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if ( c1 == c2 ) {
		cout << "1" ;
		string Rp = "" , Xp = "" ;
		Rp = Rp + s1[ 0 ] + s1[ 1 ] ;
		Xp = Xp + s2[ 0 ] + s2[ 1 ] ;
		if ( Rp == Xp ) {
			cout << "1" ;
			string Xc = "" , Rc = "" ;
			Xc = Xc + s2[ 2 ] , Rc = Rc + s1[ 2 ] ;
			bool tyc = ( Xc == "A" && ( Rc == "B" || Rc == "C" ) ) || ( Xc == "D" && Rc == "F" ) || ( Xc == "B" && ( Rc == "A" || Rc == "C" ) ) || ( Xc == "C" && ( Rc == "B" || Rc == "A" ) ) ;
			if ( tyc ) {
				cout << "1" ;
				bool xl = ( Xc == "D" && Rc == "F" ) || ( Xc == "A" && Rc == "B" ) || ( Xc == "B" && ( Rc == "C" || Rc == "A" ) ) || ( Xc == "C" && Rc == "B" ) ;
				if ( xl ) {
					cout << "1" ;
				} else {
					cout << "0" ;
				}
			} else {
				cout << "00" ;
			}
		} else {
			cout << "000" ;
		}
	} else {
		cout << "0000" ;
	}
	return 0 ;
}
