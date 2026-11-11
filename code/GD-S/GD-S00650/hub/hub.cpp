#include<bits/stdc++.h>
#define N 2000007
#define ll long long
using namespace std;
int c, T, n, k;
vector<int> g[N];
bool use[N];
int dis[N];
void dfs(int u, int fa){
	for(int i = 0;i < g[u].size();i++){
		int v = g[u][i];
		if(v == fa || use[v])continue;
		if(dis[v] > dis[u] + 1){
			dis[v] = dis[u] + 1;
			dfs(v, u);
		}
	}
}
bool vis[N];
void dfs2(int u, int fa){
	vis[u] = 1;
	for(int i = 0;i < g[u].size();i++){
		int v = g[u][i];
		if(v == fa || !use[v])continue;
		dfs2(v, u);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> T;
	while(T--){
		int ans = 1e7;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			g[i].clear();
		}
		for(int i = 1, u, v;i < n;i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1;i < (1 << n);i++){
			int cnt = 0;
			for(int j = 1;j <= n;j++){
				use[j] = vis[j] = 0;
				dis[j] = 1e7;
				if((i >> j - 1) & 1){
					cnt++;
					use[j] = 1;
					if(cnt > k)break;
				}
			}
			if(cnt > k || cnt < k)continue;
			cnt = 0;
			for(int j = 1;j <= n;j++){
				if(use[j]){
					dis[j] = 0;
					dfs(j, 0);
					if(!vis[j]){
						cnt++;
						if(cnt > 2)break;
						dfs2(j, 0);
					}
				}
			}
			if(cnt > 2)continue;
			int d = 0;
			for(int j = 1;j <= n;j++){
				d = max(d, dis[j]);
			}
			ans = min(ans, d);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
