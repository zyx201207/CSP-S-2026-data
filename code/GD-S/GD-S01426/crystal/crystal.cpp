#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const ll N = 5e5 + 3;
ll n, m, a[N];
ll sum[N], s[N];
ll check(ll j) {
	ll l = 1, r = j;
	ll res = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (sum[j] - m <= sum[mid] + (mid - 1) * (a[j] - a[mid])) {
			res = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return res;
}
void solve() {
	cin >> n >> m;
	for (ll i = 1;i <= n;++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1;i <= n;++i) s[i] = s[i - 1] + a[i];
	for (ll i = 1;i <= n;++i) {
		sum[i] = a[i] * (i - 1) - s[i - 1];
	}
	ll ans = 0;
	for (ll i = 2;i <= n;++i) {
		ll j = check(i);
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
	return;
} 
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
}
