#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e3;
ll a[N + 3], dis[N + 3];
ll n, d, s, t, cnt, mi = 1e18;
void dfs(ll u, ll fa) {
	dis[u] = dis[fa] + 1;
	if (u == t) {
		if (dis[u] == mi) {
			cnt++;
		} else if (dis[u] < mi) {
			mi = dis[u];
			cnt = 1;
		}
		return ;
	}
	for (ll i = u + 1; i <= t; i++) {
		if (a[i] - a[u] <= d) {
			dfs(i, u);
		}
	}
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			s = i;
			ll pos = upper_bound(a + 1, a + 1 + n, a[i] + d) - a;
			if (a[pos] - a[i] <= d) break;
			for (ll j = pos; j <= n; j++) {
				cnt = 0;
				mi = 1e18;
				memset(dis, 0, sizeof(dis));
				t = j;
				dfs(s, 0);
				if (cnt == 2) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
