#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,k;
int dfn[35],dis[35][35];
vector<int> g[35];

void dfs(int u,int fa) {
	dfn[u] = 1;
	for(int i = 0;i < g[u].size();i ++) {
		int to = g[u][i];
		if(to == fa || !vis[to]) {
			continue;
		}
		
		dfs(to,u);
	}
}

int get1(int x) {
	int cnt = 0;
	while(x) {
		x = x - (x & (-x));
		cnt ++;
	}
	return cnt;
}

void solve1() {
	cin >> n >> k;
	
	int u,v;
	for(int i = 1;i <= n;i ++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i = 1;i < (1 << n);i ++) {
		if(get1(i) != k) continue;
		memset(vis,0,sizeof(vis));
		memset(dis,127,sizeof(dis));
		memset(dfn,0,sizeof(dfn));
		
		int cnt = 0;
		for(int j = 1;j <= n;j ++) {
			int x = (1 << (j - 1)) & i;
			if(x) {
				vis[j] = 1;
				dis[j] = 0;
			}
		}
		
		for(int j = 1;j <= n;j ++) {
			dis[]
		}
		
		for(int j = 1;j <= n;j ++) {
			if(!dfn[j] && vis[j] == 1) {
				dfs(j,-1);
				cnt ++;
			}
		}
		
		if(cnt > 2) {
			continue;
		}
		
		for(int k = 1;k <= n;k ++) {
			for(int i = 1;i <= n;i ++) {
				for(int j = 1;j <= n;j ++) {
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		
		
	}
}


signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> c >> t;
	while(t --) {
		solve1();
	}
	
	return 0;
}
