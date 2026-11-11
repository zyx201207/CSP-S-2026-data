/*
feng ceng tu ?
dijkstra ?
*/
#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second

using namespace std;

#define INF 1e18
#define N 505
#define M 500005
#define D 25
#define Q 100005 

ll c, n, m, d, q, w[M];
ll cnt[M];
vector<ll> a[N], t[N];
vector<pii> g[D * M];
priority_queue<pii, vector<pii>, greater<pii>> pq;
ll dis[D * M];
bool vis[D * M];

inline ll getid(ll i, ll j) {
	return m * i + j;
}

inline void addedge(ll u, ll v, ll w) {
	g[u].push_back({v, w});
	g[v].push_back({u, w});
	return;
}

inline void dijkstra(ll s) {
	for (int i = 1; i <= m * d; i++) dis[i] = INF;
	for (int i = 1; i <= m * d; i++) vis[i] = 0;
	dis[s] = 0;
	
	pq.push({dis[s], s});
	while (pq.size()) {
		int u = pq.top().se; pq.pop();
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (auto p : g[u]) {
			ll v = p.fi, w = p.se;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	return;
}

vector<pii> qry[N];
ll ans[Q];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, tmpa, tmpt; j <= k; j++) {
			cin >> tmpa >> tmpt;
			
			cnt[tmpa]++;
			if (j > 1) addedge(getid(cnt[tmpa], tmpa), getid(cnt[a[i].back()], a[i].back()), 0);
			
			a[i].push_back(tmpa), t[i].push_back(tmpt);
			addedge(tmpa, getid(cnt[tmpa], tmpa), tmpt);
		}
	}
	
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		qry[u].push_back({v, i}); 
	}
	
	for (int i = 1; i <= m; i++) {
		if (!qry[i].size()) continue;
		
		dijkstra(i);
		
		for (int j = 0; j < qry[i].size(); j++) {
			int v = qry[i][j].fi, id = qry[i][j].se;
			ans[id] = w[i] + dis[v] + w[v];
		}
	}
	
	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";

	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

