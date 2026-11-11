#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;
int n, k, ans; 
int use[N], vis[N], dis[N];
vector <int> adj[N];

void Dfs(int x){
	vis[x] = 1;
	for(auto v: adj[x]){
		if(vis[v] || !use[v]) continue;
		Dfs(v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	int C, T; cin >> C >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) adj[i].clear();
		for(int i = 1; i < n; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = 1e9 + 7;
		for(int i = 1; i < (1 << n); ++i){
			int cnt = 0;
			for(int j = 0; j < n; ++j){
				if(i&(1<<j)) use[j+1] = 1, cnt++;
				else use[j+1] = 0;
				dis[j+1] = 1e9 + 7;
				vis[j+1] = 0;
			}
			if(cnt != k) continue;
			cnt = 0;
			for(int j = 0; j < n; ++j){
				if(i&(1<<j)){
					if(!vis[j+1]){
						cnt++;
						Dfs(j+1);
					}
				}
			}
			if(cnt > 2) continue;
			queue <int> Q;
			for(int j = 1; j <= n; ++j){
				vis[j] = 0;
				if(use[j]) Q.push(j), dis[j] = 0, vis[j] = 1;
			}
			while(!Q.empty()){
				int u = Q.front(); Q.pop();
				for(auto v: adj[u]){
					if(vis[v]) continue;
					dis[v] = dis[u] + 1;
					Q.push(v); vis[v] = 1;
				}	
			}
			int res = 0;
			for(int j = 1; j <= n; ++j) res = max(res, dis[j]);
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
	return 0;
}