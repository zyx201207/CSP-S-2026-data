#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, a[1000005];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	for (int i = 1; i <= n; i++) {
		m -= (i - l) * (a[i] - a[i - 1]);
		while (m < 0) {
			m += a[i] - a[l];
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
