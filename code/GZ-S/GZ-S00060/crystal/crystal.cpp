//GZ-S00060 贵阳市第一中学 王羿翔
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n, m; cin >> n >> m;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	auto check = [&](ll k) -> bool {
		ll now = 0;
		for (ll i = 1; i < k; i++) now += a[k] - a[i];
		ll res = now;
		for (ll i = k + 1; i <= n; i++) {
			now += (k - 1) * (a[i] - a[i - 1]);
			now -= a[i - 1] - a[i - k];
			res = min(res, now);
		}
		return res <= m;
	};
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1; 
	}
	cout << r;
	return 0;
}
