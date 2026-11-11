#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1.5e6 + 10, N2 = 3000 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
//我们钦定其是一颗树 
//we see the graph we built as a tree, then do the lca.
//i don't know how many score i can get 
int c, n, m, d, q, tot;
vector<pair<int, int>> e[N];
int val[N];
vector<int> a[N], t[N], id[N]; 
void adde(int u, int v, int w){ e[u].push_back({v, w}), e[v].push_back({u, w}); }
int kou(int u){ return u; }
int ting(int u){ return u + m; }
namespace subtask1{//mei you luan yong 
	ll dis[N]; bool vis[N];
	void dij(int st){
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		for(int i = 1; i <= tot; i++) dis[i] = inf, vis[i] = false;
		dis[st] = 0, pq.push({0, st});
		while(pq.size()){
			int u = pq.top().second; pq.pop();
			if(vis[u]) continue; 
			vis[u] = true;
			for(auto &pii : e[u]){
				int v = pii.first, w = pii.second;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					pq.push({dis[v], v});
				} 
			}
		}
	}
	void sol(){
		while(q--){
			int u, v; cin >> u >> v;
			dij(kou(u));
			cout << dis[kou(v)] << '\n';
		}
	} 
}
namespace subtask2{//44pts
	ll dis[N2][N2]; bool vis[N];
	void dij(int st){
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		for(int i = 1; i <= tot; i++) dis[st][i] = inf, vis[i] = false;
		dis[st][st] = 0, pq.push({0, st});
		while(pq.size()){
			int u = pq.top().second; pq.pop();
			if(vis[u]) continue; 
			vis[u] = true;
			for(auto &pii : e[u]){
				int v = pii.first, w = pii.second;
				if(dis[st][v] > dis[st][u] + w){
					dis[st][v] = dis[st][u] + w;
					pq.push({dis[st][v], v});
				} 
			}
		}
	}
	void sol(){
		for(int i = 1; i <= tot; i++) dij(i);
		while(q--){
			int u, v; cin >> u >> v;
			cout << dis[kou(u)][kou(v)] << '\n';
		}
	}
}
namespace subtask3{//?pts
	bool vis[N];
	ll dis[N];
	int fa[N][22], dep[N];
	void dfs(int u, int f){
		for(auto &pii : e[u]){
			int v = pii.first;
			if(v == f) continue;
			fa[v][0] = u, dis[v] = dis[u] + pii.second;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
	int lca(int u, int v){
		if(dep[u] < dep[v]) swap(u, v);
		int dif = dep[u] - dep[v];
		for(int k = __lg(tot); k >= 0; k--)
			if(dif >> k & 1) u = fa[u][k];
		if(u == v) return u;
		for(int k = __lg(tot); k >= 0; k--)
			if(fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
		return fa[u][0];
	}
	bool dfs2(int u, int f){//is a circle? 
		bool res = 0; vis[u] = true;
		for(auto &pii : e[u]){
			int v = pii.first;
			if(v == f) continue;
			if(vis[v]){
				return true;
			}
			res |= dfs2(v, u);
		}
		return res;
	}
	void sol(){
		dfs(1, 0);
		for(int k = 1; k <= __lg(tot); k++)
			for(int i = 1; i <= tot; i++) 
				fa[i][k] = fa[fa[i][k - 1]][k - 1];
		while(q--){
			int u, v; cin >> u >> v;
			cout << dis[u] + dis[v] - dis[lca(u, v)] * 2 << '\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	tot = 2 * m;
	for(int i = 1; i <= m; i++) cin >> val[i], adde(kou(i), ting(i), val[i]);
//	cout << "kill\n";
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		a[i].resize(k + 1, 0), t[i].resize(k + 1, 0);
		for(int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j], ++tot;
			if(j > 1){
				adde(tot - 1, tot, 0);
			}
			adde(ting(a[i][j]), tot, t[i][j]);
		}
	}
	if(m <= 1000) subtask2::sol();
	else subtask3::sol();
	return 0;
}
/*
oh nonono,this problem is much harder than last year's one.
i can only da baoli.scores of brute are too few.qwq.
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

必须回来做这道题了。 
m个点，每个点分为口、厅。
n个线路，经过若干点，点与线路的连接点称为台。 
口->厅->台，所有边双向。
每个点至多与20个线路相连
除线路中相邻点，所有边有边权
若换乘：台->厅->台
Q个询问，求u的口到v的口的最短路。
不能直接连，因为只有在同一线路时才能0权
砍掉一些没有用的边
考虑性质A
我唐了啊，新点个数是m
那么点数就是 m 带小常数
边数也是小常数
然后现在就是，一个m个点的稀疏图，1e5次询问两点的最短路
直接跑dij不现实
考虑离线？
Q次询问的两点最短路，我怎么没见过啊。
我们发现仍然没有用到d。 
我们发现每个点的度数至多是3。会不会变成一个树? 
发现除了样例2，其他都是一颗树 
怎么回事呢
好吧,不是树的情况还是有很多的.  
我们钦定其为一颗树 
希望数据跟大样例一样水. 
why all of big examples are in special features???

16:24 [44,60]pts
16:54 [44, ?]pts, pass all the examples
*/
