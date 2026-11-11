#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
typedef pair<int, ll> PII;
typedef pair<ll, int> PLL;

const int N = 5e5 + 10, NN = 510;
const ll INF = 1ll << 60;

int c, n, m, d, q;
ll w[N];

namespace sol1 {
	vector<PII> G[N + NN];
	ll d[N + NN];
	ll dis(int s, int t) {
		for (int i = 1; i <= n + m; i++) {
			d[i] = INF;
		}
		d[s] = 0;
		priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
		pq.push({0, s});

		while (!pq.empty()) {
			auto o = pq.top();
			pq.pop();
			ll di = o.first;
			int u = o.second;

			if (di > d[u]) continue;
			for (auto i : G[u]) {
				int v = i.first;
				ll w = i.second;
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					pq.push({d[v], v});
				}
			}
		}

		return d[t];
	}
	void sol() {
		for (int i = 1; i <= n + m; i++) G[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			for (int j = 1; j <= k; j++) {
				int to;
				ll t;
				cin >> to >> t;
				G[m + i].pb({to, t});
				G[to].pb({m + i, t});
			}
		}
		for (int tc = 1; tc <= q; tc++) {
			int u, v;
			cin >> u >> v;
			cout << dis(u, v) + w[u] + w[v] << "\n";
		}
	}
}

ll val[NN][N];
ll f[NN][NN];
vector<int> S[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> n >> m >> d >> q;
	if (q <= 200) {
		sol1::sol();
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			val[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		S[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int to;
			ll t;
			cin >> to >> t;
			val[i][to] = t;
			S[to].pb(m + i);
		}
	}

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = INF;
		}
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int x = 0; x < S[i].size(); x++) {
			for (int y = x + 1; y < S[i].size(); y++) {
				int nx = S[i][x] - m, ny = S[i][y] - m;
				ll Val = 1ll * val[nx][i] + val[ny][i];
				f[nx][ny] = min(f[nx][ny], Val);
				f[ny][nx] = min(f[ny][nx], Val);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <=n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int tc = 1; tc <= q; tc++) {
		int u, v;
		cin >> u >> v;
		ll ans = INF;
		for (int i = 0; i < S[u].size(); i++){
			for (int j = 0; j < S[v].size(); j++) {
				int nx = S[u][i] - m, ny = S[v][j] - m;
				if (f[nx][ny] == INF) continue;
				ans = min(ans, (ll)w[u] + w[v] + val[nx][u] + val[ny][v] + f[nx][ny]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

/*
5 5
1 2 4 8 9
*/
