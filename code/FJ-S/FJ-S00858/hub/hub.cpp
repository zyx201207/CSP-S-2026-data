#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e6 + 10;
const int Log = 30;
int c, t;

int n, k;

struct Edge{
	int next;
	int to;
	int dis;
}edge[N];

int edge_num, head[N];

void add(int x, int y) {
	edge[++ edge_num].next = head[x];
	edge[edge_num].to = y;
	head[x] = edge_num;
	
	return ;
}

int fa[N], dep[N], f[N][Log + 10], ans;
bool vis[N];

void dfs(int x, int FA) {
	fa[x] = FA;
	for(int i = head[x] ; i ; i = edge[i].next) {
		int v = edge[i].to;
		if(dep[v] != 0)
			continue;
		dep[v] = dep[x] + 1;
		
		dfs(v, x);
	}
	
	return ;
}

int LCA(int x, int y) {
	if(dep[x] < dep[y])
		swap(x, y);
		
	for(int i = Log ; i >= 0 ; i --) 
		if(dep[f[x][i]] >= dep[y])
			x = f[x][i];

	if(x == y) return x;

	for(int i = Log ; i >= 0 ; i --) {
		if(f[x][i] != f[y][i]) {
			
			x = f[x][i];
			y = f[y][i];
		}
	}
	
	return fa[x];
}

int disa(int x, int y) {
	int G = LCA(x, y);
	return (dep[x] - dep[G]) + (dep[y] - dep[G]);
}

void DFS(int x, int num, int L) {

	if(L > 2) 
		return ;
	if(num == k) {
		
		int C = 0;
		for(int i = 1 ; i <= n ; i ++) {
			int cnt = 0x3f3f3f3f3f3f3f3f;
			for(int j = 1 ; j <= n ; j ++) {
				if(!vis[j])
					continue;
				cnt = min(cnt, disa(i, j));
			}
			C = max(cnt, C);
		}
		ans = min(ans, C);
	}
	else {
		if(vis[fa[L]]) {
			vis[x] = true;
			for(int i = head[x] ; i ; i = edge[i].next) {
				int v = edge[i].to;
				if(v == fa[x])
					continue;
				DFS(v, num + 1, L);
			}
			vis[x] = false;
			
			for(int i = head[x] ; i ; i = edge[i].next) {
				int v = edge[i].to;
				if(v == fa[x])
					continue;
				DFS(v, num, L);
			}
		}
		else {
			vis[x] = true;
			for(int i = head[x] ; i ; i = edge[i].next) {
				int v = edge[i].to;
				if(v == fa[x])
					continue;
				DFS(v, num + 1, L + 1);
			}
			vis[x] = false;
			
			for(int i = head[x] ; i ; i = edge[i].next) {
				int v = edge[i].to;
				if(v == fa[x])
					continue;
				DFS(v, num, L);
			}
		}
	}
	return ;
}
signed main() {
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	
	cin >> c >> t;
	
	while(t --) {
		memset(dep, 0, sizeof(dep));
		memset(fa, 0, sizeof(fa));
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		ans = 0x3f3f3f3f3f3f3f3f;
		
		cin >> n >> k;
		for(int i = 1 ; i < n ; i ++) {
			int x, y;
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		
		dep[1] = 1;
		dfs(1, -1);
		
		for(int i = 1 ; i <= n ; i ++) 	
			f[i][0] = fa[i];
		
		for(int i = 1 ; i <= Log ; i ++) 
			for(int j = 1 ; j <= n ; j ++) 
				f[j][i] = f[f[j][i - 1]][i - 1];
		
		DFS(1, 0, 0);
		
		cout << ans << '\n';
	}
	
	return 0;
}
