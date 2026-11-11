#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int Case, Task;
int n, k;
int dis[20][20];
int dep[N], fa[N];
struct uds{
	int fa[N], sz[N];
	void Init(){
		for(int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
	}
	int Get(int x){
		return (x == fa[x] ? x : fa[x] = Get(fa[x]));
	} 
	void merge(int x, int y){
		x = Get(x), y = Get(y);
		if(x == y) return;
		if(sz[x] < sz[y]) fa[x] = y, sz[y] += sz[x], sz[x] = 0;
		else fa[y] = x, sz[x] += sz[y], sz[y] = 0;
	}
	bool con(int x, int y){
		return Get(x) == Get(y);
	}
}A;
struct Edge{
	int head[N], tot;
	struct edge{
		int to, pre;
	}e[N << 1];
	void clear(){
		memset(head, 0, sizeof(int) * (n + 5));
		tot = 0;
	}
	void add(int x, int y){
		e[++tot] = {y, head[x]};
		head[x] = tot;
	}
	void dfs(int u, int fat){
		fa[u] = fat;
		dep[u] = dep[fat] + 1;
		for(int i = head[u]; i; i = e[i].pre){
			int v = e[i].to;
			if(v == fat) continue;
			dfs(v, u); 
		}
	}
	int Get(int x, int y){
		int u = x, v = y;
		if(dep[u] < dep[v]) swap(u, v);
		while(dep[u] > dep[v]) u = fa[u];
		while(u != v){
			u = fa[u], v = fa[v];
		}
		return dep[x] + dep[y] - 2 * dep[u];
	}
	bool check(int S){
		A.Init();
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(S & (1 << i)) cnt++;
		}
		if(cnt > k) return 0; 
		for(int u = 1; u <= n; u++){
			if((S & (1 << (u - 1))) == 0) continue;
			for(int i = head[u]; i; i = e[i].pre){
				int v = e[i].to;
				if((S & (1 << (v - 1))) && !A.con(u, v)){
					A.merge(u, v);
					cnt--;
				}
			}
		}
		return cnt <= 2;
	}
}E;
void Main(){
	E.clear();
	cin >> n >> k;
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		E.add(u, v);
		E.add(v, u);
	}
	E.dfs(1, 0);
	if(Case <= 3){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = E.Get(i, j);
			}
		}
		int ans = n;
		for(int S = 0; S < (1 << n); S++){
			if(!E.check(S)) continue;
			int mx = 0;
			for(int u = 1; u <= n; u++){
				int mn = n;
				if(S & (1 << (u - 1))) continue;
				for(int v = 1; v <= n; v++){
					if(S & (1 << (v - 1))) mn = min(mn, dis[u][v]);
				}
				mx = max(mx, mn);
			}
			ans = min(ans, mx); 
		}
		printf("%d\n", ans);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Case >> Task;
	while(Task--) Main();
	return 0;
} 
