#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int c, T, n, k;
int u, v;
vector<int> g[N];
int f[N][25], dep[N];
bool vis[N], bj[N];
int a[N];
int ans;

void dfs(int u, int fa){
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for(auto v: g[u]){
		if(v == fa)	continue;
		dfs(v, u);
	}
}

void dfs1(int u){
	vis[u] = true;
	for(auto v: g[u]){
		if(!bj[v] || vis[v])	continue;
		dfs1(v);
	}
}

int lca(int x, int y){
	int u = x, v = y;
	if(dep[x] != dep[y]){
		if(dep[x] > dep[y])	swap(x, y);
		for(int j = 20;j >= 0;j--){
			if(dep[f[y][j]] >= dep[x])
				y = f[y][j];
		}
	}
	if(x != y){
		for(int j = 20;j >= 0;j--){
			if(f[x][j] != f[y][j]){
				x = f[x][j], y = f[y][j];
			}
		}
		x = f[x][0];
	}
	return dep[u] - dep[x] + dep[v] - dep[x];
}

void work(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++){
		g[i].clear();
		for(int j = 20;j >= 0;j--){
			f[i][j] = 0;
		}
	}
	for(int i = 1;i < n;i++){
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	for(int j = 1;(1 << j) <= n;j++){
		for(int i = 1;i + (1 << j) - 1 <= n;i++){
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	ans = 1e9;
	for(int i = 1;i < (1 << n);i++){
		for(int j = 1;j <= n;j++)	vis[j] = bj[j] = 0;
		int tot = 0;
		for(int j = 0;j < n;j++){
			if((i >> j) & 1){
				a[++tot] = j + 1;
				bj[j + 1] = true;
			}
		}
		if(tot != k)	continue;
		int num = 0;
		for(int i = 1;i <= tot;i++){
			if(!vis[a[i]]){
				num++;
				dfs1(a[i]);
			}
		}
		if(num > 2)	continue;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(bj[i])	continue;
			int res = 1e9;
			for(int j = 1;j <= tot;j++){
				res = min(res, lca(i, a[j]));
			}
			sum = max(sum, res);
		}
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		work();
	}
	return 0;
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
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/

