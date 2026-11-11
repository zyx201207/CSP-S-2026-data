#include <bits/stdc++.h>
#define int long long

const int maxn = 5e2 + 1 ;
const int maxm = 1e3 + 1 ;
int c, n, m, d, q, ans;
bool vis[maxn][maxm] ;
int t[maxn][maxm], w[maxm] ;
std::vector<int> b[maxm], G[maxn] ;

inline int min(int a, int b) { return a < b ? a : b ; }

void dfs(int k, int u, int r, int cnt) {
	if(cnt > ans) return ;
	if(vis[k][r]) {
		ans = min(ans, cnt + t[k][r]) ;
		return ;
	}
	for(auto v : G[k]) {
		if(v == u) continue ;
		for(auto x : b[v]) {
			if(x == k) continue ;
			dfs(x, v, r, cnt + t[k][v] + t[x][v]) ;
		}
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	std::ios::sync_with_stdio(0) ;
	std::cin.tie(0) ;
	std::cin >> c >> n >> m >> d >> q ;
	for(int i=1 ; i<=m ; i++) std::cin >> w[i] ;
	for(int i=1 ; i<=n ; i++) {
		int k ; std::cin >> k ;
		for(int j=1 ; j<=k ; j++) {
			int a ; std::cin >> a ; std::cin >> t[i][a] ;
			b[a].push_back(i) ;
			G[i].push_back(a) ;
			vis[i][a] = true ;
		}
	}
	for( ; q ; q--) {
		int l, r ; std::cin >> l >> r ;
		ans = 1e16 ;
		for(auto k : b[l]) dfs(k, l, r, t[k][l]) ;
		std::cout << ans + w[l] + w[r] << '\n' ;
	}
	return 0 ;
}

