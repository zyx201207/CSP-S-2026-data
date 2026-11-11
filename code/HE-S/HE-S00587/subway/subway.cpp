#include<bits/stdc++.h>

using namespace std;
//bool ST;
const int maxn = 505;
const int maxm = 5e5 + 5;
#define ll long long
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxn][maxn], dis[maxn][maxn], w[maxm];
map<int, ll> g[maxm];
vector<int> idx[maxm];
vector<pair<int, ll>> e[maxn];

int n, m;
void dijkstra(int s) {
	priority_queue<pair<ll, int>> q;
	q.push({0, s});
	dist[s][s] = 0;
	vector<bool>vis(n + 1, false);
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (auto i : e[u]) {
			int v = i.first;
			ll w = i.second;
			if (dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w;
				q.push({-dist[s][v], v});
			}
		}
	}
}

void coder() {
	int c, d, q;
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dis[i][j] = INF;
			dis[j][i] = INF;
			dist[i][j] = INF;
			dist[j][i] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; ++j) {
			int a;
			ll t;
			cin >> a >> t;
			g[i][a] = t;
			idx[a].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (auto k : g[i]) {
			for (int j : idx[k.first]) {
				if (g[j].count(k.first)) {
					dis[i][j] = min(dis[i][j], k.second + g[j][k.first]);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (dis[i][j] != INF) {
				e[i].emplace_back(j, dis[i][j]);
				e[j].emplace_back(i, dis[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	while(q--) {
		int s, t;
		cin >> s >> t;
		ll ans = INF;
		for (auto i : idx[s]) {
			for (auto j : idx[t]) {
				ans = min(ans, w[s] + w[t] + g[i][s] + g[j][t] + dist[i][j]);
			}
		}
		cout << ans << '\n';
	}
}


//bool ED;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	cerr << (fabs(&ST - &ED) / 1024.0 / 1024.0) << "MB\n";
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
//	clock_t start = clock();
	
	coder();
	
//	clock_t end = clock();
//	cerr << double(end - start) / CLOCKS_PER_SEC << '\n';
	return 0;
}
