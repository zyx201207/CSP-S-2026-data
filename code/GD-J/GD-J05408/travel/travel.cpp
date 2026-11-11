#include<bits/stdc++.h>
using namespace std;
char rw,xw ;
int rh,xh ;
string x,rc,xc;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rc ;
	cin >> x;
	rh = (x[0]-'0')*10+x[1]-'0' ;
	rw = x[2] ;
	cin >> xc ;
	cin >> x;
	xh = (x[0]-'0')*10+x[1]-'0' ;
	xw = x[2] ;
	if(xc != rc) {
		cout << "0000" ;
		return 0;
	}else cout << 1 ;
	if(xh != rh) {
		cout << "000" ;
		return 0;
	}else cout << 1 ;
	if(xw < 'D' && rw < 'D' || xw > 'C' && rw > 'C') cout << 1 ;
	else {
		cout << "00" ;
		return 0;
	}
	if(xw-1 == rw || rw-1 == xw || rw == 'D' && xw == 'F' || xw == 'D' && rw == 'F') cout << 1 ;
	else cout << "0" ;
	return 0;
} 
