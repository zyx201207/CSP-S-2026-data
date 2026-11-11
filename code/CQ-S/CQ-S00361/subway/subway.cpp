#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define rand rnd
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 510, M = 500010;
struct edge{
	int v, nex;
}; 
int dis[N][N], w[M];
vector<int> a[N], t[N];
vector<pair<int, int> > bel[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1, k; i <= n; i++){
		cin >> k;
		a[i].resize(k + 5), t[i].resize(k + 5);
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
			bel[a[i][j]].push_back({i, t[i][j]});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = 1; i <= m; ++i){
//		cout << i << "\n";
		for(int j = 0; j < bel[i].size(); ++j){
			for(int k = 0; k <= j - 1; ++k){
				int v = bel[i][j].fi, v1 = bel[i][k].fi, t1 = bel[i][j].se, t2 = bel[i][k].se;
				dis[v][v1] = min(dis[v][v1], t1 + t2);
				dis[v1][v] = dis[v][v1];
//				cout << j << " " << k << " " << v << " " << v1 << " " << t1 << " " << t2 << "\n"; 
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			for(int k = 1; k <= n; ++k){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			cout << dis[i][j] << " ";
//		} 
//		cout << "\n";
//	}
	for(int i = 1, u, v; i <= q; i++){
		cin >> u >> v;
		int ans = 1e18;
		for(auto x : bel[u]){
			for(auto y : bel[v]){
//				cout << x.fi << " " << y.fi << " " << x.se << " " << y.se << " " << dis[x.fi][y.fi] << "\n"; 
				ans = min(dis[x.fi][y.fi] + x.se + y.se, ans);
			}
		}
		
		cout << ans + w[u] + w[v] << "\n";
	}
	
	return 0;
}
/*

这题的本质是：
出发点一定，然后我要通过选择哪个站台去使得答案尽可能小，这是在模拟一个东西

考虑一下每个点可以到哪里：aijk

i可以通过j路线到k

然后的话这就是个dp

显然这不行，我们考虑优化，i可以通过第j路线？

本质是i枚举站台，然后站台枚举到哪里，然后继续往下，以此重复 

我们只要把路线找到是不是就行了？

x属于哪些路线，y属于哪些路线，如果说需要x到y的话

让路线找共同的，如果没有的话，就需要一个间接的

考虑每一个和哪些点属于同一个路线

我觉得需要路线连路线

只要路线有交集，就可以相连

这样的话最坏n方

然后x从20个路线找，也是找20个路线有y的 

求得一个答案

这是B的做法，因为，不需要每个换乘的T都是一样的

考虑换乘的T是：ti,j + tc,k

那么我只需要对每一个换乘的可能进行一个取最小值不就行了

就是交集可能有很多，我看一下哪个代价最小

一共500个点，和边，可以直接进行一个全源最短路？

然后我们就知道两个路线换乘的最小代价

400 * 100000

然后建图的复杂度是？因为我要考虑每个路线的点交集，所以是O(n)的？差不多，应该是(mlogm) 

枚举是400 * O(m)

怎么感觉考虑回来了

 
*/
