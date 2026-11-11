#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 7, maxm = 5e2 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct Edge {
	int v; ll w;
	bool operator < (const Edge &o) const {
		return w > o.w;
	}
};
ll ti[maxn];
vector<Edge> G[maxm];
vector<int> g1[maxm], g2[maxn];
map<int, ll> val[maxm];
ll d[maxm][maxm];
int c, n, m, q;

void dj(int s, ll dis[]) {
	for(int i = 1; i <= m; i++) dis[i] = inf;
	
	priority_queue<Edge> pq;
	dis[s] = 0; pq.push({s, dis[s]});
	while(!pq.empty()) {
		auto tmp = pq.top(); pq.pop();
		int u = tmp.v;
		if(dis[u] < tmp.w) continue;
		for(auto e : G[u]) {
			int v = e.v; ll w = e.w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
} 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int D;
	cin >> c >> m >> n >> D >> q;
	for(int i = 1; i <= n; i++) cin >> ti[i];
	for(int i = 1; i <= m; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int id, v; cin >> id >> v;
			g1[i].push_back(id);
			g2[id].push_back(i);
			val[i][id] = v;
		}
	}
	
	for(int i = 1; i <= m; i++) {
		for(int j = i + 1; j <= m; j++) {
			ll w = inf;
			for(int u : g1[i]) {
				if(val[j].find(u) != val[j].end()) w = min(w, val[i][u] + val[j][u]);
			}
			if(w != inf) {
				G[i].push_back({j, w});
				G[j].push_back({i, w});
			}
		}
	}
	for(int i = 1; i <= m; i++) dj(i, d[i]);
	
	while(q--) {
		int u, v; cin >> u >> v;
		ll ans = inf;
		for(int i : g2[u]) for(int j : g2[v]) ans = min(ans, d[i][j] + val[i][u] + val[j][v]);
		cout << ans + ti[u] + ti[v] << "\n";
	}
	return 0;
}
