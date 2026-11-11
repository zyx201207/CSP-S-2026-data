#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int c, t, n, k, d[N], f[N][25], ru[N], gen, ans = 1e18;
bool vis[N], shu[N];
vector <int> g[N];
void DFS(int u){//搜连通块 
	vis[u] = 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(vis[v]) continue;
		if(shu[v]) DFS(v);
	}
}
bool check(){//判断是否最多为两个连通块 
	memset(vis, 0, sizeof(vis)); 
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(shu[i] && !vis[i]){
			cnt++;
			DFS(i);
		}
	}
	return (cnt <= 2);
}
void dfs(int u){
	d[u] = d[f[u][0]] + 1;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v == f[u][0]) continue;
		f[v][0] = u;
		dfs(v);
	}
}
int lca(int u, int v){
	if(d[u] < d[v]) swap(u, v);
	for(int i = 20; i >= 0; i--)
		if(d[f[u][i]] >= d[v]) u = f[u][i];
	if(u == v) return u;
	for(int i = 20; i >= 0; i--){
		if(f[u][i] != f[v][i]){
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}
void xuan(int now, int last){//暴力dfs出N个选K的方案 
	if(now == k){
		if(check()){		
			int ban = 0;
			for(int i = 1; i <= n; i++){
				if(shu[i]) continue;
				int mn = 1e9;
				for(int j = 1; j <= n; j++)
					if(shu[j]) mn = min(mn, d[i] + d[j] - 2 * d[lca(i, j)]);
				ban = max(ban, mn);
			}
			ans = min(ans, ban);
		}
		return;
	}
	for(int i = last; i <= n; i++){
		if(!shu[i]){
			shu[i] = 1;
			xuan(now + 1, i);
			shu[i] = 0;
		}
		
	}
} 
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		ans = 1e18;
		for(int i = 1; i <= n; i++) g[i].clear(), ru[i] = 0, d[i] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 20; j++) f[i][j] = 0;
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			ru[v]++;
		}
		for(int i = 1; i <= n; i++){
			if(ru[i] == 0){
				gen = i;
				break;
			}
		}
		dfs(gen);
		for(int j = 1; j <= 20; j++)
			for(int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
		xuan(0, 1);
		cout << ans << '\n';
	}
	return 0;
}
/*题外话：T4暴力分不知道多少
猛然想到：树上任意两点的距离可以用LCA求，d[u]+d[v]-2d[lca(u,v)] 
那我直接N个选K个暴力搜索，然后模拟枚举理论上15pts
坏了我105行写完发现有问题，根有概率判断错，判断对倒是能骗15pts啊啊啊啊啊 
为啥我忘了怎么判断根节点啊啊啊啊啊啊 
坏了现在只能听天由命了希望数据过水 
*/ 
