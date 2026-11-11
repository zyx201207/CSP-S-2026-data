#include <bits/stdc++.h>
using namespace std ;
const int N = 15 ; 
int c, t, n, k, cnt, ans ;
vector<int> g[N] ;
int a[N], mark[N] ;
int dfs(int u, int fa){
	if(mark[u]) return mark[u] ;
	for(int v : g[u])
		if(a[v])
			if(v != fa)
				mark[u] = dfs(v, u) ;
	if(mark[u]) return mark[u] ;
	return mark[u] = ++cnt ;
}
int dfs2(int u, int fa){
	int w = 1 ;
	for(int v : g[u])
		if(v != fa) 
		w = max(dfs(v, u) + 1, w) ;
	return w ;
}
int main(){
	freopen("hub.in", "r", stdin) ;
	freopen("hub.out", "w", stdout) ;
	cin >> c >> t ;
	while(t--){
		cin >> n >> k ;
		for(int i = 1; i <= n; i++)
			while(g[i].size()) g[i].pop_back() ; 
		for(int i = 1; i < n; i++){
			int u, v ;
			cin >> u >> v ;
			g[u].push_back(v) ;
			g[v].push_back(u) ;
		}
		if(c <= 3){
			ans = 2e9 ; 
			for(int i = 1; i < (1 << n); i++)
				if(__builtin_popcount(i) == k){
					memset(a, 0, sizeof(a)) ;
					memset(mark, 0, sizeof(mark)) ; 
					cnt = 0 ;
					for(int j = 0; j < n; j++)
						if((i >> j) & 1) a[j + 1] = 1 ;
					for(int j = 1; j <= n; j++)
						if(a[j]) dfs(j, 0) ;
					if(cnt <= 2){
						int tmp = 1e9 ;
						for(int j = 1; j <= n; j++)
							tmp = min(tmp, dfs2(j, 0)) ;
						ans = min(tmp, ans) ;
					}
				}
			cout << ans << "\n" ;
		}
	}
	return 0 ;
}
