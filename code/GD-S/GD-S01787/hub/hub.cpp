#include<bits/stdc++.h>
using namespace std;
#define vec std::vector
#define ll long long
#define i128 __int128
#define endl "\n"
#define pb push_back
ll read(){
	ll num = 0; int f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + (c ^ 48);
		c = getchar();
	}
	return num * f;
}
int n, k;
void CZW(int id) {
//	cout << "TEST"  << endl;
	n = read(), k = read();
	if (id <= 3) {
		int ans = 2e9;
		vec<vec<int>> adj(n + 1);
		for (int i = 1; i < n; ++i) {
			int u = read(), v = read();
			adj[u].pb(v), adj[v].pb(u);
		}
		
		
		
		// LCA
		vec<int> dep(n + 1, 0), fa(n + 1, 0);
			function<void(int, int)> dfs = [&](int u, int fath) {
				dep[u] = dep[fath] + 1;
				fa[u] = fath;
				for (int v : adj[u]) {
					if (v == fath) continue;
					dfs(v, u);
				}
			};
			dfs(1, 0);
//			cout << "dep: " << endl;
//			for (int i = 1; i <= n; ++i) cout << dep[i] << ' ';
//			cout << endl;
//			cout << "fa: " << endl;
//			for (int i = 1; i <= n; ++i) cout << fa[i] << ' ';
//			cout << endl << "---------" << endl;
			vec<vec<int>> lca(n + 1, vec<int> (n + 1, 0));
			for (int i = 1; i <= n; ++i) {
				lca[i][i] = i;
				for (int j = i + 1; j <= n; ++j) {
					int u = i, v = j;
					if (dep[u] < dep[v]) swap(u, v);
					while (dep[u] > dep[v]) u = fa[u];
					while (u != v) u = fa[u], v = fa[v];
					lca[i][j] = lca[j][i] = u;
				}
			}
//			for (int i = 1; i <= n; ++i) {
//				for (int j = 1; j <= n; ++j) {
//					cout << lca[i][j] << ' ';
//				}
//				cout << endl;
//			}
		//--------------------------------------------
		
		
		
		vec<char> is(n + 1, false);
		vec<int> col(n + 1, 0); int cnt = 0;
		for (int msk = 0; msk < (1 << n); ++ msk) {
			if (__builtin_popcount(msk) != k) continue;
			vec<int> dis(n + 1, 2e9);
			for (int i = 1; i <= n; ++i) col[i] = 0, is[i] = false;
			cnt = 0;
//			cout << "Node : " << endl;
			for (int i = 0; i < n; ++i) {
				if (msk >> i & 1) {
					is[i + 1] = true;
//					cout << i + 1 << ' ';
				}
			}
//			cout << endl << "-------" << endl;
			for (int i = 1; i <= n; ++i) {
				if (is[i] && !col[i]) {
					queue<int> q;
					q.push(i);
					col[i] = ++cnt;
					while(!q.empty()) {
						int u = q.front();
						q.pop();
						for (int v : adj[u]) {
							if (!is[v]) continue;
							if (col[v]) continue;
							q.push(v);
							col[v] = cnt;
						}
					}
				}
			}
//			cout << "cnt: " << cnt << endl;
//			for (int i = 1; i <= n; ++i) cout << col[i] << ' ';
//			cout << endl;
			if (cnt > 2) continue;
			int res = 0;
//			cout << (int)is[1] << endl;
			for (int i = 1; i <= n; ++i) {
				if (is[i]) continue;
				for (int j = 1; j <= n; ++j) {
					if (!is[j] || i == j) continue;
//					cout << "i, j: " << i << ' ' << j << endl;
//					cout << "lca_i,j: " << lca[i][j] << endl;
//					cout << "val: " << dep[i] - dep[lca[i][j]] << ' ' << dep[j] - dep[lca[i][j]] << endl;
					dis[i] = min(dis[i], dep[i] - dep[lca[i][j]] + dep[j] - dep[lca[i][j]]);
				}
//				if (dis[i] == 2) cout << "dis: " << dis[i] << endl;
				res = max(res, dis[i]);
			}
//			cout << "res: " << res << endl;
			ans = min(ans, res);
		}
		cout << ans << endl;
		return ;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int id = read(), Test = read();
	while (Test --) CZW(id);
	return 0;
}

