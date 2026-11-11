#include <bits/stdc++.h>
using namespace std;

int n, m, a[2005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	if (m == 1) {
		for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
		cout << ans;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(a[i] & a[j], ans);
		cout << ans;
		return 0;
	} else {
		for (int i = 0; i < (1 << n); i++) {
			if (__builtin_popcount(i) == m) {
				int sa = -1;
				for (int j = 0; j < n; j++) {
					if (i & (1 << j)) {
						if (sa == -1) sa = a[j + 1];
						else sa &= a[j + 1];
					}
				}
				ans = max(ans, sa);
			}
		}
		cout << ans;
	}
	return 0;
}
