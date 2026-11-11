/*
er fen jike
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

#define N 500005

ll n, m, a[N];

inline bool check(ll x) {
	ll mn = 1e18, lst = 0;
	for (int i = 1; i <= x; i++) lst += a[x] - a[i];
	
	mn = lst;
	
	for (ll i = 2; i + x - 1 <= n; i++) {
		lst = lst - (a[i + x - 2] - a[i - 1]) + (a[i + x - 1] - a[i + x - 2]) * x;
		mn = min(mn, lst);
	}
	return mn <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	ll l = 1, r = n, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	
	cout << ans;
	
	return 0;
}
