#include<bits/stdc++.h>
#define int long long
using namespace std;
char tmp;
char acs, acg, azw;
char bcs, bcg, bzw;
bool a, b, c, d;
int xa, xb, pa, pb;
bool istc(char x, char y){
	if(x <= 'C' && y <= 'C') return 1;
	if(x >= 'D' && y >= 'D') return 1;
	return 0;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> acs >> acg;
	xa = (acs - '0') * 10 + acg - '0';
	cin >> acs >> acg >> azw ;
	pa = (acs - '0') * 10 + acg - '0';
//	cout << xa << " " << pa << endl;
	
	cin >> bcs >> bcg;
	xb = (bcs - '0') * 10 + bcg - '0';
	cin >> bcs >> bcg >> bzw ;
	pb = (bcs - '0') * 10 + bcg - '0';
//	cout << xb << " " << pb << endl;
	
	a = (xa == xb);
	b = a & (pa == pb);
	c = b & istc(azw, bzw);
	d = c & !((azw == 'A' && bzw == 'C') || (azw == 'C' && bzw == 'A'));
	cout << a << b << c << d;
	return 0;
} 
