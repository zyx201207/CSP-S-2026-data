#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
const int N = 1e6 + 5;
int id, T;
int n, k;
vector <int> e[N];
int dist[1001][1001];
int fa[N], son[N], sz[N], head[N], depth[N];
void dfs(int x, int father, int dep){
	fa[x] = father;
	depth[x] = dep;
	sz[x] = 1;
	for (int u : e[x]){
		if (u == father){
			continue;
		}
		dfs(u, x, dep + 1);
		sz[x] += sz[u];
		if (sz[u] > sz[son[x]]){
			son[x] = u;
		}
	}
	return;
}
void dfs2(int x, int he){
	head[x] = he;
	if (son[x]){
		dfs2(son[x], he);
	}
	for (int u : e[x]){
		if (u == fa[x] || u == son[x]){
			continue;
		}
		dfs2(u, u);
	}
	return;
}
int lca(int u, int v){
	while (head[u] != head[v]){
		if (depth[head[u]] < depth[head[v]]){
			swap(u, v);
		}
		u = fa[head[u]];
	}
	if (depth[u] > depth[v]){
		swap(u, v);
	}
	return u;
}
int b[N];
bool c[N];
long long ans;
void f(int x){
	if (x == k + 1){
		long long res = 0;
		for (int i = 1; i <= n; i++){
			int tmp = 1e9;
			for (int j = 1; j <= k; j++){
				tmp = min(tmp, dist[i][b[j]]);
			}
			res += tmp;
		}
		ans = min(ans, res);
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!c[i]){
			c[i] = true;
			b[x] = i;
			f(x + 1);
			c[i] = false;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	FILE("hub")
	int u, v;
	cin >> id >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			son[i] = 0;
			e[i].clear();
		}
		for (int i = 1; i < n; i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0, 1);
		dfs2(1, 1);
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				dist[j][i] = dist[i][j] = depth[i] + depth[j] - (depth[lca(i, j)] << 1);
			}
		}
		ans = 1e9;
		f(1);
		cout << ans << "\n";
	}
	return 0;
}

