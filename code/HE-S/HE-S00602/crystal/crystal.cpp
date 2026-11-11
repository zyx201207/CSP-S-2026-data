#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 5;
ll n, m, a[N], maxx = -1e18, s[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (ll j = 1; j <= n; ++j) {
		ll cst = (j - 1) * a[j] - s[j - 1];
		ll l = 1, r = j + 1;
		while (l < r) {
			ll mid = (l + r) >> 1ll;
//			cout << j << ' ' << l << ' ' << r << ' ' << mid << '\n';
			if (cst - (mid * a[j] - s[mid]) <= m) r = mid;
			else l = mid + 1;
		}
		if (cst <= m) maxx = max(maxx, j);
		maxx = max(maxx, j - r);
	}
	return cout << maxx, 0;
}
