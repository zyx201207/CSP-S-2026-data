#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5;
ll a[N + 3], qz[N + 3];
ll nww, mm, cnt, ans;
bool cmp(ll x, ll y) {
	return abs(x - nww) < abs(y - nww);
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll nw = 1; nw <= n; nw++) {
		nww = a[nw];
		mm = m;
		cnt = 0;
		sort(a + 1, a + 1 + n, cmp);
		memset(qz, 0, sizeof(qz));
		for (int i = 1; i <= n; i++) {
			qz[i] = qz[i - 1] + abs(a[i] - nww);
		}
		ll pos = upper_bound(qz + 1, qz + 1 + n, mm) - qz - 1;
		if (qz[pos] > m) pos--;

		ans = max(ans, pos);
	}
	cout << ans;
	return 0;
}
