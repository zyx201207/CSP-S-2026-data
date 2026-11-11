#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int T, dep[N], fa[N][21], mx[N], pre[N], suf[N], Son[N], top, c, K, Ans, n;
vector<int> e[N];
void clear() {
	Ans = n + 1;
	for(int i = 1; i <= n; i ++) pre[i] = suf[i] = 0;
	for(int i = 1; i <= n; i ++) e[i].clear();
}
void add(int u, int v) {
	e[u].push_back(v);e[v].push_back(u);
}
void dfs(int u, int f) {
	if(u != 1) Son[u] = top;
	dep[u] = dep[f] + 1;fa[u][0] = f;
	mx[u] = 0;
	for(auto v : e[u]) {
		if(v == f) continue;
		if(u == 1) top = v;
		dfs(v, u);
		mx[u] = max(mx[u], mx[v] + 1);
	}
	int Mx = 0;
	if(u == 1) {
		for(auto v : e[u]) {
			pre[v] = Mx;
			Mx = max(Mx, mx[v] + 1);
		}
		reverse(e[u].begin(), e[u].end()) ;
		Mx=  0;
		for(auto v : e[u]) {
			suf[v] = Mx;Mx = max(Mx, mx[v] + 1);
		}
	}
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i --) {
		if(dep[fa[x][i]] >= dep[y]) {
			x = fa[x][i];
			if(dep[x] == dep[y]) break;
		}
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i --) {
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
int dis(int x, int y) {
	int lca = LCA(x, y);
	return dep[x] + dep[y] - 2 * dep[lca];
}
void redfs(int u, int f) {
	int X = 0;
	if(u != 1) {
		X = max(pre[Son[u]], suf[Son[u]]) + dep[u] - dep[1];
	}
	X = max(X, mx[u] / 2);
	Ans = min(X, Ans);
	for(auto v : e[u]) {
		if(v == f) continue;
		redfs(v, u);
	}
}
int main() {
//	freopen("D:\\P.in", "r", stdin);
//	freopen("D:\\P.out", "w", stdout);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> c;
	cin >> T;
	while(T --) {
		cin >> n >> K;
		clear();
		for(int i = 1; i < n; i ++) {
			int u, v;cin >> u >> v;
			add(u, v);add(v, u);
		}
		dfs(1, 0);
		for(int j = 1; j <= 20; j ++) {
			for(int i = 1; i <= n;  i ++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
//		for(int i = 1; i <= n; i ++) cout << mx[i] << ' ' << Son[i] << '\n';
//		cout << pre[2] << ' ' << suf[2] << endl;
		for(int i = 0; i < (1 << n); i ++) {
			int Dis = 0;
			if(__builtin_popcount(i) != K) continue;
			for(int j = 1; j <= n; j ++) {
				int DIS = n + 1;
				for(int k = 1; k <= n; k ++) {
					if(i >> (k - 1) & 1) DIS = min(DIS, dis(j, k));
				}
				Dis = max(Dis, DIS);
			}
			Ans = min(Ans, Dis);
		}
		cout << Ans << '\n';
	}
	return 0;
}
  
