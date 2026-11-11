#include<bits/stdc++.h>
using namespace std;

int const N = 15;
int c, t, n, k, fa[N], siz[N], ans = 1e9;
vector<int>g[N];
bool vis[N];
struct Node {
	int x, w; 
};

int find_root(int u) {
	return (fa[u] == 0? u : fa[u] = find_root(fa[u]));
}

void merge(int u, int v) {//vºÏµ½uÏÂ 
	u = find_root(u), v = find_root(v);
	if(u == v) return;
	if(siz[v] > siz[u]) swap(u, v);
	fa[v] = u;
	siz[u] += siz[v];
	siz[v] = 0;
}

int bfs(int st, int ed) {
	queue<Node>q;
	bool vis[N];
	memset(vis, 0, sizeof(vis));
	q.push({st, 0});
	vis[st] = true;
	while(!q.empty()) {
		int x = q.front().x, w = q.front().w;
		if(x == ed) return w;
		q.pop();
		for(auto v : g[x]) {
			if(vis[v]) continue;
			vis[v] = true;
			q.push({v, w + 1});
		}
	}
	return 1e9;
}

void solve() {
	for(int i = 1; i <= n; i++) siz[i] = 1, fa[i] = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == false) continue;
		for(auto v : g[i]) {
			if(vis[v] == false) continue;
			merge(i, v);
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == false) continue;
		if(siz[i] > 0) cnt++;
	}
	if(cnt > 2) return;
	
	int r = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		int d = 1e9;
		for(int j = 1; j <= n; j++) {
			if(vis[j] == false) continue;
			d = min(d, bfs(i, j));
		}
		r = max(r, d); 
	}
	ans = min(ans, r);
}

void dfs(int x, int cnt) {
	if(cnt == k) {
		solve();
		return;
	}else if(x > n) return;
	if(n - x + 1 < k - cnt) return;
	dfs(x + 1, cnt);
	vis[x] = true;
	dfs(x + 1, cnt + 1);
	vis[x] = false;
}

void init() {
	memset(fa, 0, sizeof(fa));
	for(int i = 1; i <= n; i++) g[i].clear();
	memset(vis, 0, sizeof(vis));
	ans = 1e9;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		init(); 
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		cout << ans << endl;
//		for(int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}

