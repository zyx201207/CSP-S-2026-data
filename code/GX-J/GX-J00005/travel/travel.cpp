#include <bits/stdc++.h>
using namespace std ;

int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	string a , b , c , d ;
	bool flaga = false , flagb = false , flagc = false ;
	cin >> a >> b >> c >> d ;
	if (a == c) {
        flagc = true ;
		cout << "1" ;
	} else {
		cout << "0" ;
	}
	if (b[0] == d[0] && b[1] == d[1] &&  flagc) {
	    flaga = true ;
        cout << "1" ;
	} else {
	    cout << "0" ;
	}
	if (((b[2] <= 'C' && d[2] <= 'C') ||(b[2] >= 'D' && d[2] >= 'D')) && flaga && flagc) {
        flagb = true ;
        cout << "1" ;
	} else {
	    cout << "0" ;
	}
	if (abs((b[2]-'0')-(d[2]-'0')) == 1 && flaga && flagb && flagc) {
		cout << "1" ;
	} else {
		cout << "0" ;
	}
	return 0 ;
}
