#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
vector<int> e[N];
int dep[N], Fa[N][20];
int col[N];
int fa[N];
int n, k;
int ans = 1e18;
int find(int x) {
	if(fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void Init(int u, int fa) {
	dep[u] = dep[fa] + 1;
	Fa[u][0] = fa;
	for(int i = 1; i <= 20; i++) {
		Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
	}
	for(int v : e[u]) {
		if(v == fa) continue;
		Init(v, u);
	}
}
int Lca(int x ,int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--) {
		if(dep[Fa[x][i]] >= dep[y]) {
			x = Fa[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i--) {
		if(Fa[x][i] != Fa[y][i]) {
			x = Fa[x][i];
			y = Fa[y][i];
		}
	}
	return Fa[x][0];
}
int dis(int x, int y) {
	return dep[x] + dep[y] - 2 * dep[Lca(x, y)];
}
int solve() {
	vector<int> num;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;	
		if(col[i]) {
			num.push_back(i);
		}
	}
//	cout << '\n';
	int res = k;
	for(int i = 1; i <= n; i++) {
		for(int v : e[i]) {
			if(col[v] && col[i]) {
				int a = find(v);
				int b = find(i);
				if(a != b) {
					res--;
					fa[a] = b;
				}
			}
		}
	}
	if(res > 2) return 1e18;
//	cout << res << '\n';
	int res2, res3 = 0;
	for(int i = 1; i <= n; i++) {
		res2 = 1e18;
		for(int u : num) {
			res2 = min(res2, dis(i, u));
		}
		res3 = max(res3, res2);
	}
	return res3;
}
void dfs(int u, int res) {
	if(u > n) {
		if(res == k) ans = min(ans, solve());
		return ;
	}
	col[u] = 1;
	dfs(u + 1, res + 1);
	col[u] = 0;
	dfs(u + 1, res);
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		ans = 1e18;
		memset(Fa, 0, sizeof(Fa));
		memset(dep, 0, sizeof(dep));
		cin >> n >> k;
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dep[0] = 1;
		Init(1, 0);
//		cout << dis(1, 5);
		dfs(1, 0);
//		return 0;
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) e[i].clear();
	}
}
