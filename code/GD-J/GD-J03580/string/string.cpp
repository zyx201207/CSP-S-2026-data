#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int n, a[MAX];
char c[MAX];
long long ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int L = 1, R = n, l = a[1], r = a[n];
	char lc = c[1], rc = c[n];
	while (L <= R) {
		int mn = min(l, r);
		l -= mn;
		r -= mn;
		if (lc != rc) {
			ans += mn;
		}
		if (l == 0) {
			l = a[++L];
			lc = c[L];
		}
		else {
			r = a[--R];
			rc = c[R];
		}
	}
	cout << ans;
	return 0;
}
