#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2000010;
ll n, d;
ll x[N];
vector<ll> g[N];
queue<ll> q;
ll cnt[N], dis[N];
void bfs(ll u) {
	for (ll i = 1; i <= n; i++) {
		dis[i] = LLONG_MAX;
		cnt[i] = 0;
	}
	dis[u] = 0;
	cnt[u] = 1;
	q.push(u);
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		for (ll i = 0; i < g[u].size(); i++) {
			ll v = g[u][i];
			if (dis[v] == LLONG_MAX) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			} else if (dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (ll i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (i != j && abs(x[i] - x[j]) <= d) {
					g[i].push_back(j);
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			bfs(i);
			for (ll j = 1; j <= n; j++) {
				if (cnt[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}
