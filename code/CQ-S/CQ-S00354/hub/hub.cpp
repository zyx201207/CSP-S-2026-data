#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int n, k, fa[N], dis[N], res = INF;
bitset<N> vis, vis1;
vector<int> e[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

void dij(ll s) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	memset(dis, INF, sizeof dis);
	dis[s] = 0, pq.push(make_pair(dis[s], s));
	while(!pq.empty()) {
		pair<ll, ll> p = pq.top(); pq.pop();
		ll u = p.second;
		for(int v : e[u]) {
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				pq.push(make_pair(dis[v], v));
			}
		}
	}
}

void dfs(int x) {
	if(x > k) {
		vis1 = 0;
		iota(fa, fa + n + 1, 0);
		for(int i = 1; i <= n; i++) {
			for(int j : e[i]) {
				if(vis[i] && vis[j]) {
					merge(i, j);
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(vis[i] && !vis1[find(i)]) vis1[find(i)] = true, ++cnt;
		if(cnt > 2) return ;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			dij(i);
			int diss = INF;
			for(int j = 1; j <= n; j++) if(vis[j]) diss = min(diss, dis[j]);
			ans = max(ans, diss);
		}
		res = min(res, ans);
		return ;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		dfs(x + 1);
		vis[i] = false;
	}
}

void solve() {
	res = INF;
	for(int i = 1; i <= n; i++) e[i].clear();
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		e[u].emplace_back(v), e[v].emplace_back(u);
	}
	dfs(1);
	cout << res << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}

