#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 505, M = 5e5 + 5;
ll c, n, m, d, q, w[M], dis[N][N], dep[N + M + 5], tmp;
vector<ll> vt[M + N + 5];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; ++i) cin >> w[i];
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	for (ll i = 1, k; i <= n; ++i) {
		cin >> k;
		for (ll j = 1; j <= k; ++j) {
			ll x, y;
			cin >> x >> y;
			if (!tmp) tmp = y;
			if (i + m < N) { dis[i + m][x] = y; dis[x][i + m] = y; }
			vt[i + m].push_back(x);
			vt[x].push_back(i + m);
		}
	}
	if (c >= 12 && c <= 19) {
		for (ll i = 1; i <= q; ++i) {
			ll x, y;
			cin >> x >> y;
			unordered_map<ll, bool> vis;
			queue<ll> q;
			q.push(x);
			dep[x] = 0;
			while (!q.empty()) {
				ll u = q.front(); q.pop();
				vis[u] = true;
				for (ll v : vt[u]) {
					if (vis[v]) continue;
					q.push(v);
					dep[v] = dep[u] + 1;
				}
			}
			cout << dep[y] * tmp + w[x] + w[y] << '\n';
		}
	} else {
		dis[0][0] = 0;
		for (ll k = 1; k <= n + m; ++k)
			for (ll i = 1; i <= n + m; ++i)
				for (ll j = 1; j <= n + m; ++j)
					if (i != j && dis[i][j] > dis[i][k] + dis[k][j]) 
						dis[i][j] = dis[i][k] + dis[k][j];
		for (ll i = 1; i <= q; ++i) {
			ll x, y;
			cin >> x >> y;
			cout << dis[x][y] + w[x] + w[y] << '\n';
		}
	}
	return 0;
}
