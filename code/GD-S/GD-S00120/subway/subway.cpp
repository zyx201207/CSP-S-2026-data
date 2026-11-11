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
	一共有 500 个线路，但是点数高达 5e5？ 
	但这么出提示也很明显了吧？考虑将线路看成点，两个点之间的最短路就是它们所在同一个站台的距离和最小值 
	这样就是 O(d_i^2+n^3)=O(kd+n^3) 的，十分对啊 
	那查询咋做呢 
	直接 O(d) 枚举不就行了 
	感觉挺对的 
	*/
	
	const int N = 500, M = 500000;
	std::vector <pll> v[M + 5];
	ll dis[N + 5][N + 5];
	ll a[M + 5];
	ll n, m, d, q; 
	
	void solve(){
		std::cin >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++) std::cin >> a[i];
		for(int i = 1; i <= n; i++){
			int k;
			std::cin >> k;
			for(int j = 1; j <= k; j++){
				int x, y;
				std::cin >> x >> y;
				v[x].push_back({i, y});
			}
		}
		memset(dis, 63, sizeof(dis));
		for(int i = 1; i <= m; i++){
			for(auto it:v[i]){
				for(auto it2:v[i]){
					if(it.first == it2.first) continue;
					dis[it.first][it2.first] = dis[it2.first][it.first] = std::min(dis[it.first][it2.first], it.second + it2.second); 
				}
			}
		}
		for(int i = 1; i <= n; i++){
			dis[i][i] = 0;
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		while(q--){
			int x, y;
			std::cin >> x >> y;
			ll ans = 0x3f3f3f3f3f3f3f3fll;
			for(auto it:v[x]){
				for(auto it2:v[y]){
					ans = std::min(ans, dis[it.first][it2.first] + it.second + it2.second);
				}
			}
			std::cout << ans + a[x] + a[y] << '\n';
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cjdst::init();
	std::cin >> c;
	for(int _ = 1; _ <= T; _++){
		cjdst::solve();
	} 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
