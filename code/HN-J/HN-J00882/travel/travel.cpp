#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a, b, c, d;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	
	if (a == c) {
		cout << 1;
		if (b[0] + b[1] == d[0] + d[1]) {
			cout << 1;	
			char e = b[2], f = d[2];
			if (((e == 'A' || e == 'B' || e == 'C') && (f == 'A' || f == 'B' || f == 'C')) || ((e == 'E' || e == 'F') && (f == 'E' || f == 'F'))) {
				cout << 1;
				if (e > f) {
					char tmp = e;
					e = f, f = tmp;
				}
				if ((e == 'A' && f == 'B') || (e == 'B' && f == 'C') || (e == 'E' && f == 'F')) cout << 1;
				else cout << 0;	
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	
	return 0;
}
