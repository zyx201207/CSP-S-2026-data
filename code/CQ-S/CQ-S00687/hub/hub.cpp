#include <bits/stdc++.h>

const int maxn = 1e3 + 1 ;
std::vector<int> G[maxn], a ;
int n, k, ans ;
int siz[maxn], siz2[maxn], l[maxn], l2[maxn] ;
int vis[maxn] ;

inline int max(int a, int b) { return a > b ? a : b ; }
inline int min(int a, int b) { return a < b ? a : b ; }

void dfs(int u, int fa) {
	siz[u] = siz2[u] = 0 ;
	vis[u] = 1 ;
	for(auto v : G[u]) {
		if(v == fa) continue ;
		dfs(v, u) ;
		if(siz[v] >= siz[u]) {
			l2[u] = l[u] ;
			l[u] = v ;
			siz2[u] = siz[u] ;
			siz[u] = siz[v] + 1 ;
		}
		else if(siz[v] >= siz2[u]) siz2[u] = siz[v] + 1, l2[u] = v;
	}
	return ;
}

void find(int u) {
	if(G[u].size() == 1) { a.push_back(u) ; return ; }
	find(l[u]) ;
	a.push_back(u) ;
	return ;
}

void fd(int u) {
	a.push_back(u) ;
	if(G[u].size() == 1) return ;
	fd(l[u]) ;
	return ;
}

void Solve() {
	std::cin >> n >> k ; ans = n >> 1 ;
	for(int i=1 ; i<=n ; i++) G[i].clear() ;
	for(int i=1 ; i<n ; i++) {
		int u, v ;
		std::cin >> u >> v ;
		G[u].push_back(v) ;
		G[v].push_back(u) ;
	}
	if(k == n) {
		std::cout << "0\n" ;
		return ;
	}
	if(k >= (n + 1 >> 1)) {
		std::cout << "1\n" ;
		return ;
	}
	while(k --) {
		int len = 0, id = 0 ;
		for(int i=1 ; i<=n ; i++) if(vis[i] == 1) vis[i] = 0 ;
		for(int i=1 ; i<=n ; i++) if(! vis[i]) dfs(i, i) ;
		for(int i=1 ; i<=n ; i++) {
			if(vis[i] == 1) {
				if(siz[i] + siz2[i] + 1 > len) len = siz[i] + siz2[i] + 1, id = i ;
			}
		}
		find(l[id]) ;
		a.push_back(id) ;
		if(siz2[id] != 0)fd(l2[id]) ;
		vis[a[len >> 1]] = 2 ;
		a.clear() ;
		ans = min(ans, len >> 1) ;
	}
	std::cout << ans - 1 << '\n' ;
	return ;
}

signed main() {
	freopen("hub.in", "r", stdin) ;
	freopen("hub.out", "w", stdout) ;
	std::ios::sync_with_stdio(0) ;
	std::cin.tie(0) ;
	int c, _ ;
	std::cin >> c >> _ ;
	while(_--) Solve() ;
	return 0 ;
}

