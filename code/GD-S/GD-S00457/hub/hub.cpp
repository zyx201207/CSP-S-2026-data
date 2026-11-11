#include <bits/stdc++.h>

#define ll long long
#define N 1000005
#define INF 0x3f3f3f3f
using namespace std ;
int n , op , T , k , hd[N] , dep[N] , fa[N][20] , tot ;
bool vis[N] ;
struct edge {
	int v , nxt ;
}e[N << 1];
int cnt , ans ;
void df1(int u , int f) {
	dep[u] = dep[f] + 1 ;
	fa[u][0] = f ;
	for(int i = 0 ; i < 20 ; i++)fa[u][i + 1] = fa[fa[u][i]][i] ;
	for(int i = hd[u] ; i ; i = e[i].nxt) {
		int v = e[i].v ;
		if(v == f)continue ;
		df1(v , u) ; 
	}
}
int get_lca(int x , int y) {
	if(dep[x] < dep[y])swap(x , y) ;
	for(int i = 20 ; i >= 0 ; i--) {
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i] ;
	}
	if(x == y)return x ;
	for(int i = 20 ; i >= 0 ; i--) {
		if(fa[x][i] != fa[y][i])x = fa[x][i] , y = fa[y][i] ;
	}
	return fa[x][0] ;
}
void df2(int u , int f) {
	if(!vis[u] && !vis[f])cnt++ ;
	for(int i = hd[u] ; i ; i = e[i].nxt) {
		int v = e[i].v ;
		if(v == f)continue ;
		df2(v , u) ; 
	}
} 
int main() {

	ios :: sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;

	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	
	cin >> op >> T ;
	while(T--) {
		ans = INF ;
		tot = 0 ;
		cin >> n >> k ;
		for(int i = 1 ; i <= n ; i++)hd[i] = 0 ;
		for(int i = 1 , u , v ; i < n ; i++) {
			cin >> u >> v ;
			e[++tot] = {u , hd[v]} ;
			hd[v] = tot ;
			e[++tot] = {v , hd[u]} ;
			hd[u] = tot ;	
		}
		df1(1 , 0) ;
		for(int s = 1 ; s < (1 << n) ; s++) {
			vector<int> v ;
			int num = 0 ;
			for(int j = 0 ; (1 << j) <= s ; j++)vis[j + 1] = 0 ;
			for(int j = 0 ; (1 << j) <= s ; j++) {
				if(s & (1 << j)) {
					num++ ; 
					vis[j + 1] = 1 ;
					v.push_back(j+1) ;
				}
			}
			if(num != k)continue ;
			cnt = 0 ;
			df2(1 , 0) ;
			if(cnt > 2)continue ;
			int res = 0 ;
			for(int i = 1 ; i <= n ; i++) {
				int tmp = INF ;
				for(int j : v) {
					int lca = get_lca(j , i) ;
					int dis = dep[j] + dep[i] - 2 * dep[lca] ;
					tmp = min(dis , tmp) ;
				}
				res = max(res , tmp) ;
			}
			ans = min(ans , res) ;
		} 
		cout << ans << '\n' ;
	}
	return 0 ;

}

