#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	if(a==c) {
		cout << "1";
	}
	else cout << "0";
	if(b[0]+b[1] == d[0]+d[1] && a==c) {
		cout << "1";
	}
	else cout << "0";
	if(b[0]+b[1] == d[0]+d[1] && a==c && ((b[2]<='C'&&d[2]<='C') || (b[2]>'C'&&d[2]>'C'))) {
		cout << "1";
	}
	else cout << "0";
	if(b[0]+b[1] == d[0]+d[1] && a==c && abs(b[2]-d[2]) == 1 && ((b[2]!='C' && d[2] !='D') && (b[2]!='D' && d[2] !='C'))) {
		cout << "1";
	}
	else cout << "0";
	return 0;
}
