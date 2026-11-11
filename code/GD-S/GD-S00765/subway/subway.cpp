#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
constexpr ll N = 510, M = 5e5 + 10, INF = 1e18;
int c, n, m, d, q, x, y;
ll ans;
array<int, M> w, cnt;
array<array<ll, N>, N> dis, dis1;
array<array<pii, 22>, M> lns;
bitset<N> vis;
void dij(ll s) {
	vis.reset();
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.emplace(0, s);
	while(q.size()) {
		auto i = q.top();
		q.pop();
		if(vis[i.second]) {
			continue;
		}
		vis.set(i.second);
		for(int j = 1; j <= n; j++) {
			if(dis1[s][j] > dis1[s][i.second] + dis[i.second][j]) {
				dis1[s][j] = dis1[j][s] = dis1[s][i.second] + dis[i.second][j];
				q.emplace(dis1[s][j], j);
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			dis[i][j] = dis[j][i] = dis1[i][j] = dis1[j][i] = INF;
		}
	}
	for(int i = 1, k; i <= n; i++) {
		cin >> k;
		for(int j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			for(int l = 1, v; l <= cnt[a]; l++) {
				v = lns[a][l].first;
				dis[v][i] = dis[i][v] = min(dis[v][i], 1ll * lns[a][l].second + t);
			}
			lns[a][++cnt[a]] = {i, t};
		}
	}

	for(int i = 1; i <= n; i++) {
		dij(i);
		for(int j = 1; j <= n; j++) {
			dis[i][j] = dis1[i][j];
		}
	}

/*
	for(ll i = 1; i <= n; i++) {
		for(ll j = i + 1; j <= n; j++) {
			for(ll k = 1; k <= n; k++) {
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
*/
	while(q--) {
		cin >> x >> y;
		ans = INF;
		for(int i = 1; i <= cnt[x]; i++) {
			for(int j = 1; j <= cnt[y]; j++) {
				ans = min(ans, 1ll * w[x] + w[y]
						+ lns[x][i].second + lns[y][j].second
						+ dis[lns[x][i].first][lns[y][j].first]);
			}
		}
		cout << ans << '\n';
	}
}

