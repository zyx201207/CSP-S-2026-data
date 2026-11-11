#include<bits/stdc++.h>
using namespace std;

string a, b, c, d;

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	int as, cs, bs, ds;
	as = (a[0] - '0') * 10 + (a[1] - '0');
	cs = (c[0] - '0') * 10 + (c[1] - '0');
	bs = (b[0] - '0') * 10 + (b[1] - '0');
	ds = (d[0] - '0') * 10 + (d[1] - '0');
	if (as != cs) {
		cout << "0000";
		return 0;
	}
	if (bs != ds) {
		cout << "1000";
		return 0;
	}
	if (!(((b[2] >= 'A' && b[2] <= 'C') && (d[2] >= 'A' && d[2] <= 'C')) || ((b[2] >= 'D' && b[2] <= 'F') && (d[2] >= 'D' && d[2] <= 'F')))) {
		cout << "1100";
		return 0;
	}
	if (abs((int)b[2] - (int)d[2]) != 1 || (b[2] == 'C' && d[2] == 'D') || (d[2] == 'C' && b[2] == 'D')) {
		cout << "1110";
		return 0;
	} 
	cout << "1111";
	return 0;
}
