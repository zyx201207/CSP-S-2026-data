#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 2e5 + 2;

string a, b, x, y;
char p1, p2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> x >> b >> y;
	p1 = x[2], p2 = y[2];
	if (a[0] == b[0] && a[1] == b[1]) {
		cout << 1;
		if (x[0] == y[0] && x[1] == y[1]) {
			cout << 1;
			if ((p1 <= 'C' && p2 <= 'C') || (p1 > 'C' && p2 > 'C')) {
				cout << 1;
				if (p1 > p2) swap(p1, p2);
				if (p2 - p1 == 1 || (p1 == 'D' && p2 == 'F')) cout << 1;
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	cout << endl;
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
