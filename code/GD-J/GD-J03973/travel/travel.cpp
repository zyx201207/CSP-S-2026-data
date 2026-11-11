#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int r1, r2, r3, t1, t2, t3;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a[0] == 0) r1 = a[1] - '0';
	else {
		r1 = a[0] - '0';
		r1 = r1 * 10 + (a[1] - '0');
	}
	if(c[0] == 0) t1 = c[1] - '0';
	else {
		t1 = c[0] - '0';
		t1 = t1 * 10 + (c[1] - '0');
	}
	if(b[0] == 0) r2 = b[1] - '0';
	else {
		r2 = b[0] - '0';
		r2 = r2 * 10 + (b[1] - '0');
	}
	r3 = b[2] - 'A' + 1;

	if(d[0] == 0) t2 = d[1] - '0';
	else {
		t2 = d[0] - '0';
		t2 = t2 * 10 + (d[1] - '0');
	}
	t3 = d[2] - 'A' + 1;

	if(t1 != r1) cout << "0000";
	else if(t2 != r2) cout << "1000";
	else if((r3 < 4 && t3 > 3) || (r3 > 3 && t3 < 4)) cout << "1100";
	else if(r3 - 1 != t3 && t3 - 1 != r3) cout << "1110";
	else cout << "1111";
	return 0;
}
