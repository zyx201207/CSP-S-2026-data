#include <bits/stdc++.h>
using namespace std;

char x, r, c1, c2;
int xc, xs, rc, rs;

char g() {
	char c = getchar();
	while ((c < '0' || c > '9') && (c < 'A' || c > 'F'))
		c = getchar();
	return c;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	c1 = g(), c2 = g();
	xc = (c1 - '0') * 10 + c2 - '0';
	c1 = g(), c2 = g(), x = g();
	xs = (c1 - '0') * 10 + c2 - '0';
	c1 = g(), c2 = g();
	rc = (c1 - '0') * 10 + c2 - '0';
	c1 = g(), c2 = g(), r = g();
	rs = (c1 - '0') * 10 + c2 - '0';
	if (xc == rc) {
		cout << '1';
		if (xs == rs) {
			cout << '1';
			if ((x <= 'C' && r <= 'C') || (x > 'C' && r > 'C')) {
				cout << '1';
				if (x > r)
					swap(x, r);
				cout <<
					((
					(x == 'A' && r == 'B') ||
					(x == 'B' && r == 'C') ||
					(x == 'D' && r == 'F')));
			}
			else
				cout << "00";
		}
		else
			cout << "000";
	}
	else
		cout << "0000";
	return 0;
}
