#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
const int N = 5e5 + 10;
int n, m, d, q, a[N];
ll W[N], t[N], dis[510][20010];
ll Dis[2][N];
bool vis[N];
struct edge {int v; ll w;};
vector<edge> g[N];
struct node {
	int id;
	ll s;
};
vector<node> vv[N];
void dij(int st, ll *dis) {
	priority_queue<pli, vector<pli>, greater<pli>> q;
	for(int i = 1; i <= m + n; i++) dis[i] = 1e18, vis[i] = 0;
	q.push({dis[st] = 0, st});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : g[u]) {
			int v = e.v; ll w = e.w;
			if(dis[v] > dis[u] + w) dis[v] = dis[u] + w, q.push({dis[v], v});
		}
	}
}
vector<int> dis[510];
void bfs(int st) {
	queue<int> q;
	for(int i = 1; i <= m; i++) dis[st - m][i] = -1;
	q.push(st); dis[st - m][st] = 0;
	while(!q.empty()) {
		int u = q.front();
		for(auto e : g[u]) {
			int v = e.v;
			if(dis[v] == -1) dis[st - m][v] = dis[st - m][u] + 1, q.push(v);
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int Ca; scanf("%d%d%d%d%d", &Ca, &n, &m, &d, &q); 
	for(int i = 1; i <= m; i++) scanf("%lld", &W[i]);
	for(int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		for(int j = 1; j <= k; j++) scanf("%d%lld", &a[j], &t[j]), vv[a[j]].push_back({i, t[j]});
		for(int j = 1; j <= k; j++) g[a[j]].push_back({m + i, t[j]}), g[m + i].push_back({a[j], t[j]});
	}
	if(Ca <= 15) {
		for(int i = 1; i <= n; i++) dij(m + i, dis[i]);
		while(q--) {
			int u, v; scanf("%d%d", &u, &v);
			ll ans = 1e18;
			for(auto kk : vv[v]) ans = min(ans, dis[kk.id][u] + kk.s);
			printf("%lld\n", ans + W[u] + W[v]);
		}
	}
	else if(20 <= Ca && Ca <= 21) {
		for(int i = 1; i <= n; i++) dij(m + i, Dis[i]);
		while(q--) {
			int u, v; scanf("%d%d", &u, &v);
			ll ans = 1e18;
			for(auto kk : vv[v]) ans = min(ans, dis[kk.id][u] + kk.s);
			printf("%lld\n", ans + W[u] + W[v]);
		}
	}
	else {
		for(int i = 1; i <= n; i++) {
			dis[i].resize(m + n + 5);
			bfs(m + i);
		}
		while(q--) {
			int u, v; scanf("%d%d", &u, &v);
			for(auto kk : vv[v]) ans = min(ans, dis[kk.id][u] + kk.s);
			printf("%lld\n", ans + W[u] + W[v]);
		}
	}
	return 0;
}

