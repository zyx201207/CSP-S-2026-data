#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll a[N], c[N], m;
int n;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll mx = -1e18, mn = 1e18;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 5000) {
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j < i; j ++)
				c[i] += a[i] - a[j];
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= i; j ++) {
				ll x = c[i] - c[j - 1];
				if (x <= m) ans = max(ans, i - j + 1);
			}
		cout << ans;
	} else {
		int cz = a[2] - a[1];
		for (int i = 1; i <= n; i ++) c[i] = i * (i - 1) / 2 * cz;
		int x = lower_bound(c, c + n + 1, m) - c;
		if (c[x] != m) cout << x - 1;
		else cout << x;
	}
	return 0;
}
