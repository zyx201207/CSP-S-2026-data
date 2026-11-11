#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const ll N = 505, M = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int w[M];
vector<pii> g[M];

ll e[N][N];
void adde(int u, int v, ll w) {
	e[u][v] = min(e[u][v], w);
	e[v][u] = min(e[v][u], w);
}

ll d[N][N];
int c, n, m, dd, q;

void dijkstra(int s) {
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.emplace(d[s][s] = 0, s);
	while(!pq.empty()) {
		ll dis = pq.top().first, u = pq.top().second;
		pq.pop();
		
		if(dis > d[s][u]) continue;
		
		for(int v = 1; v <= n; v++) if(v != u) {
			ll w = e[u][v];
			if(d[s][u] + w < d[s][v]) {
				pq.emplace(d[s][v] = d[s][u] + w, v);
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> dd >> q;
	
	for(int i = 1; i <= m; i++) cin >> w[i];
	
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].emplace_back(i, t);
		}
	}
	
	memset(e, 0x3f, sizeof(e));
	for(int i = 1; i <= m; i++) {
		for(int a = 0; a < g[i].size(); a++) {
			for(int b = a + 1; b < g[i].size(); b++) {
				adde(g[i][a].first, g[i][b].first, g[i][a].second + g[i][b].second);
				adde(g[i][b].first, g[i][a].first, g[i][a].second + g[i][b].second);
			}
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	for(int i = 1; i <= n; i++) dijkstra(i);
	
	while(q--) {
		int x, y;
		cin >> x >> y;
		ll ans = INF;
		for(int a = 0; a < g[x].size(); a++) {
			for(int b = 0; b < g[y].size(); b++) {
				ans = min(ans, d[g[x][a].first][g[y][b].first] + g[x][a].second + g[y][b].second);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
