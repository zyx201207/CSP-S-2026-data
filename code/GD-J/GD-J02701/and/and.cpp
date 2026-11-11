#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (m == 1) {
		sort(a, a + n, greater<int> ());
		cout << a[0];
	} else if (m == 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				int t = a[i] & a[j];
				ans = max(ans, t);
			}
		}
		cout << ans;
	} else if (m == n) {
		ans = a[0];
		for (int i = 1; i < n; ++i) ans &= a[i];
		cout << ans;
	} else {
		sort(a, a + n, greater<int> ());
		ans = a[0];
		for (int i = 1; i < m; ++i) ans &= a[i];
		cout << ans;
	}
	return 0;
} 
