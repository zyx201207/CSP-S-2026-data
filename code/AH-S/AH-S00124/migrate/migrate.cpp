#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, a[2000010], s[2000010];
vector<ll> G[2000010];
bool M[200010];
pair<ll, ll> dfs(ll u, ll v) {
	if (u == v) return make_pair(0, 1);
	ll mn = 9e18, cnt = 0;
	for (ll x : G[u])
		if (!M[x]) {
			M[x] = true;
			auto u = dfs(x, v);
			if (u.first < mn) {
				mn = u.first + 1;
				cnt = 1;
			} else {
				cnt += u.second;
			}
			M[x] = false;
		}
	return make_pair(mn, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			vector<ll> tmp;
			G[i].swap(tmp);
		}
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) G[i].push_back(j);
				else break;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				for (int i = 0; i <= n; i++)
					M[i] = false;
				if (dfs(i, j).second == 2) ans++;
			}
		cout << ans << endl;
	}
	return 0;
}

