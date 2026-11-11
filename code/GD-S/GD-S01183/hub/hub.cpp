#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 7;

int cid, n, m, ans;

namespace sub1 {
	int dep[N];
	vector<int> G[N];
	int fa[N], f[20][N], d[N], vis[N], bz[N];
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void dfs(int x, int lst) {
		f[0][x] = lst;
		dep[x] = dep[lst] + 1;
		for(int v : G[x]) {
			if(v == lst) continue ;
			dfs(v, x);
		}
	}
	int LCA(int x, int y) {
		if(dep[x] < dep[y])
			swap(x, y);
		for(int c = __lg(n); c >= 0; c--) {
			if(dep[f[c][x]] >= dep[y]) {
				x = f[c][x];
			}
		}
		if(x == y) return x;
		for(int c = __lg(n); c >= 0; c--) {
			if(f[c][x] ^ f[c][y]) {
				x = f[c][x], y = f[c][y];
			}
		}
		return f[0][x];
	}
	int ck() {
		for(int i = 1; i <= m; i++) fa[d[i]] = d[i], bz[d[i]] = 0;
		for(int i = 1; i <= m; i++) {
			int x = d[i];
			for(int v : G[x]) {
				if(vis[v]) {
					int fax = find(x);
					int fay = find(v);
					if(fax == fay) continue ;
					fa[fax] = fay;
				}
			}
		}
		int cnt = 0;
		for(int i = 1; i <= m; i++) {
			if(!bz[find(d[i])]) {
				bz[find(d[i])] = 1;
				++cnt;
			}
		}
		return cnt <= 2;
	} 
	int calc() {
		int res = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue ;
			int minn = n + 1;
			for(int j = 1; j <= m; j++) {
				int lca = LCA(i, d[j]);
				int dis = dep[i] + dep[d[j]] - 2 * dep[lca];
//				cout << i << " " << d[j] << " " << lca << " " << dep[i] << " " << endl;
				minn = min(minn, dis);
			}
//			cout << 1;
			res = max(res, minn);
		}
		return res;
	}
	void dfz(int t, int ctd) {
		if(n - t + 1 < m - ctd)
			return ;
		if(t > n) {
			if(!ck()) return ;
			ans = min(calc(), ans);
			return ;
		}
		if(ctd < m) {
			vis[t] = 1, d[ctd + 1] = t;
			dfz(t + 1, ctd + 1);
			vis[t] = 0;
		}
		dfz(t + 1, ctd);
	}
	void _main_() {
		ans = n + 1;
		for(int i = 1; i <= n; i++) G[i].clear(), dep[i] = 0;
		for(int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			G[u].pb(v), G[v].pb(u);
		}
		dep[0] = 0, dfs(1, 0);
		for(int c = 1; c <= __lg(n); c++)
			for(int i = 1; i <= n; i++)
				f[c][i] = f[c - 1][f[c - 1][i]];
		dfz(1, 0);
		cout << ans << "\n";
	}
} ;

void work() {
	cin >> n >> m;
	if(n <= 10) sub1::_main_();
	else {
		if(n == m) {
			cout << 0 << "\n";
		} else {
			n = (n + 1) / 2;
			m /= 2;
			if(n % 2 == m % 2) {
				cout << (n - m) / 2 << "\n";
			} else {
				cout << (n - 1 + m) / 2 + 1 << "\n";
			}
		}
	}
}

int main() {
//	hub
//	freopen("hub5.in", "r", stdin);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> cid; int _; cin >> _;
	while(_--) work();
	return 0;
}
