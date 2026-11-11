#include<bits/stdc++.h>
using namespace std;
string a,b,m,n;
int aa,mm;
int p,q;
int x,y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> m >> n;
	aa = (a[0]-'0')*10 + a[1]-'0';
	mm = (m[0]-'0')*10 + m[1]-'0';
	p = (b[0]-'0')*10 + b[1]-'0';
	q = (n[0]-'0')*10 + n[1]-'0';
	x = int (b[2]-'A') + 1;
	y = int (n[2]-'A') + 1;
	if (aa == mm) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (p == q) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if (x <= 3 && y <= 3) cout << 1;
	else if (x > 3 && y > 3) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if (abs(x-y) == 1) cout << 1;
	else cout << 0;
	return 0;
}