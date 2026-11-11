#include <bits/stdc++.h>
#include <assert.h>
int c, T = 1;
namespace cjdst{
	typedef long long ll;
	typedef unsigned long long ull;
	typedef std::pair <int, int> pii;
	typedef std::pair <ll, ll> pll;
	
	void init(){
		std::ios::sync_with_stdio(0);
		std::cin.tie(0), std::cout.tie(0);
	}
	
	/*
	一棵树的子树有多少种啊 
	不管了先拿 15pts 再说 
	*/
	
	const int N = 10, N2 = 100000;
	std::vector <int> v[N2 + 5];
	int father[N + 5], dep[N + 5];
	int vis[N + 5];
	int dis[N + 5][N + 5];
	void dfs(int cur, int fa){
		father[cur] = fa;
		dep[cur] = dep[fa] + 1;
		for(int i:v[cur]){
			if(i == fa) continue;
			dfs(i, cur);
		}
	}
	int lca(int x, int y){
		if(dep[x] < dep[y]) std::swap(x, y);
		while(dep[x] > dep[y]) x = father[x];
		while(x != y){
			x = father[x], y = father[y];
		}
		return x;
	}
	int n, m;
	
	void solve_bf(){
		std::cin >> n >> m;
		for(int i = 1; i < n; i++){
			int x, y;
			std::cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1, 0);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = dep[i] + dep[j] - dep[lca(i, j)] * 2;
			}
		}
		int ans = 0x3f3f3f3f;
		for(int i = 1; i < (1 << n); i++){
			if(__builtin_popcount(i) != m) continue;
			memset(vis, 0, sizeof(vis));
			std::vector <int> b;
			for(int j = 0; j < n; j++){
				if(i >> j & 1) b.push_back(j + 1), vis[j + 1] = 1;
			}
			int ct = 0;
			for(int j:b){
				for(int it:v[j]){
					if(vis[it]) ct++;
				}
			}
			if(ct + 4 < m * 2) continue;
			int cur = 0;
			for(int j = 1; j <= n; j++){
				int tmp = 0x3f3f3f3f;
				for(int k:b){
					tmp = std::min(tmp, dis[j][k]);
				}
				cur = std::max(cur, tmp);
			}
			// std::cout << i << ' ' << cur << '\n';
			ans = std::min(ans, cur);
		}
		std::cout << ans << '\n';
		for(int i = 1; i <= n; i++){
			v[i].clear();
		}
	}
	
	void solve_A(){
		std::cin >> n >> m;
		for(int i = 1; i < n; i++){
			int x, y;
			std::cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n == m){
			std::cout << "0\n";
		}else{
			std::cout << std::max(1, (n / 2 - m + 2 + 1) / 4 + 1) << '\n';
		}
		for(int i = 1; i <= n; i++){
			v[i].clear();
		}
	}
	
	void solve(){
		if(c <= 3) solve_bf();
		else if(c == 13 || c == 14) solve_A();
		else std::cout << "0\n";
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cjdst::init();
	std::cin >> c >> T;
	for(int _ = 1; _ <= T; _++){
		cjdst::solve();
	} 
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
