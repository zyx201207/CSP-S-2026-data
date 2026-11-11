#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 5e5 + 10;

ll n, m;
ll a[N], pre[N];

bool check(ll mid) {
	ll res = 0;
	for (int i = 1; i < mid; i++)
		res += a[i];
	for (int i = mid; i <= n; i++) {
		if ((__int128)a[i] * (mid - 1) - res <= m)
			return true;
		res -= a[i - mid + 1];
		res += a[i];
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	ll l = 1, r = n, ans = 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	
	return 0;
}
//why T1 1h, oh no
