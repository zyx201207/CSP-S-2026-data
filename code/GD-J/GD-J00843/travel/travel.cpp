#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool f = 0, ff = 0;
	if (a == c) {
		cout << 1;
		f = 1;
	}else {
		cout << 0;
	}
	if (b[0] == d[0] && b[1] == d[1] && f) {
		cout << 1;
		ff = 1;
	}else {
		cout << 0;
	}
	if (((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) && f && ff) {
		cout << 1;
	}else {
		cout << 0;
	}
	if (((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) && (b[2] + 1 == d[2] || b[2] - 1 == d[2]) && f && ff) {
		cout << 1;
	}else {
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
