#include <bits/stdc++.h>
using namespace std;

char x, x2, a, b;
int al, bl, aw, bw;

int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	
	cin >> x >> x2;
	al = (x2 - '0') + (x - '0') * 10;
	cin >> x >> x2;
	aw = (x2 - '0') + (x - '0') * 10;
	cin >> a;
	
	cin >> x >> x2;
	bl = (x2 - '0') + (x - '0') * 10;
	cin >> x >> x2;
	cin >> b;
	bw = (x2 - '0') + (x - '0') * 10;
	
	string x = "0000";
	
	if (al == bl) {
		x[0] = '1';
		if (aw == bw) {
			x[1] = '1';
			if (a == 'D' || a == 'F' || b == 'D' || b == 'F') {
				if ((a == 'D' && b == 'F') || (a == 'F' && b == 'D')) {
					x[2] = '1';
					x[3] = '1';
				}
			} else {
				if (!((a == 'D' || b == 'F') || (a == 'F' || b == 'D'))) {
					x[2] = '1';
					if (abs ((int)a - (int)b) == 1) x[3] = '1';
				}
			}
		}
	}
	
	cout << x;
	return 0;
}
