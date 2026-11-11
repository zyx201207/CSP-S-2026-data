#include <bits/stdc++.h>
using namespace std;


char c[200010];
long long a[200010];
long long sum, n, s, ans;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (s + a[i] <= sum / 2) {
			s += a[i];
		} else {
			a[i] = sum / 2 - s;
			s = sum / 2;
		}
		while (a[i] && i < n) {
			long long t;
			t = min(a[i], a[n]);
			a[i] -= t;
			a[n] -= t;
			if (c[i] != c[n]) {
				ans += t;
			}
			if (a[n] == 0) {
				n--;
			}
//			if (i == 2) {
//				cout << a[i] << " " << a[n] << " " << t << endl;
//			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
3
1 a
10 b
1 c
*/
