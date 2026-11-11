#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const ll N = 5e5 + 5;
ll n, m, x[N], pre[N], ans;

bool check(ll mid) {
	for (ll i = mid; i <= n; i++) {
		ll cnt = x[i] * (mid - 1) - pre[i - 1] + pre[i - mid];
		if (cnt <= m) return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> x[i];
	sort(x + 1, x + n + 1);
	for (ll i = 1; i <= n; i++) pre[i] = pre[i - 1] + x[i];
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}