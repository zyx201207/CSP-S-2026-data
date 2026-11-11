#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
long long a[MAXN];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long mx = -1e18;
	if (m == 2) {
		for (long long i = 1; i <= n; ++i) {
			for (long long j = i + 1; j <= n; ++j) {
				long long cur = (a[i] & a[i + j]); 
				mx = max(cur, mx);
			}
		}
		cout << mx << '\n';
		return 0;
	}
	if (m == 1) {
		for (long long i = 1 ; i <= n; ++i) {
			mx = max(a[i], mx);
		}
		cout << mx << '\n';
		return 0;
	}
	else {
		for (long long i = 1 ; i <= n; ++i) {
			mx = max(a[i], mx);
		}
		cout << mx << '\n';
		return 0;
	}
	return 0;
}
