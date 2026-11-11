#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int c, t;
int n, k;
vector<int> e[N];
bool vis[N];
int out = 0x3f3f3f3f;
int ans = 0xc0c0c0c0;
int f[N][22];
int de[N];
void init(){
	for (int i = 1; i <= n; i++){
		e[i].clear();
	}
	memset(vis, false, sizeof(vis));
	memset(de, 0, sizeof(de));
	memset(f, 0, sizeof(f));
	out = 0x3f3f3f3f;
}
int fa[N];
int find(int x){
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if (fx == fy)
		return ;
	fa[fx] = fy;
}
void dfs_tree(int u, int fa){
	f[u][0] = fa;
	de[u] = de[fa] + 1;
	for (auto v : e[u]){
		if (v == fa)
			continue;
		dfs_tree(v, u);
	}
}
int LCA(int x, int y){
	if (de[x] < de[y])
		swap(x, y);
	int delta = de[x] - de[y];
	for (int i = 20; i >= 0; i--){
		if (delta & (1 << i))
			x = f[x][i];
	}
	if (x == y)
		return y;
	for (int i = 20; i >= 0; i--){
		if (f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x, int y){
	return de[x] + de[y] - 2 * de[LCA(x, y)];
}
void dfs(int p, int tmp_k){
	if (p == n + 1 || tmp_k == k){
		if (tmp_k != k)
			return ;
		vector<int> cur;
		for (int i = 1; i <= n; i++){
			fa[i] = i;
			if (vis[i])
				cur.push_back(i);
		}
		for (auto u : cur){
			for (auto v : e[u]){
				if (vis[v]){
					merge(u, v);
				}
			}
		}
		set<int> s;
		for (auto u : cur){
			s.insert(find(u));
		}
		if (s.size() > 2){
			return ;
		}
		ans = 0xc0c0c0c0;
		for (int i = 1; i <= n; i++){
			int d = 0x3f3f3f3f;
			for (auto v : cur){
				if (i == v){
					d = 0;
					break;
				}
				else{
					d = min(d, dis(i, v));
				}
			}
			ans = max(ans, d);
		}
		out = min(ans, out);
		return ;
	}
	vis[p] = true;
	dfs(p + 1, tmp_k + 1);
	vis[p] = false;
	dfs(p + 1, tmp_k);
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for (int cs = 1; cs <= t; cs++){
		cin >> n >> k;
		init();
		for (int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs_tree(1, 0);
		for (int j = 1; j <= 20; j++){
			for (int i = 1; i <= n; i++){
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
		dfs(1, 0);
		cout << out << "\n";
	}
}
