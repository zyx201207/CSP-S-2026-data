#include <bits/stdc++.h>
using namespace std;

int ysz, ttt, n, K;

namespace sub1{
	const int N = 15;
	const int INF = 0x3f3f3f3f;
	bool vis[N], dfv[N];
	int dis[N];
	vector <int> G[N];

	void dfs(int u, int fa){
		dfv[u] = 1;
		for(int v : G[u]){
			if(v == fa || !vis[v]) continue;
			dfs(v, u);
		}
	}
	void getdis(int u, int fa){
		if(!fa) dis[u] = 0;
		else dis[u] = min(dis[u], dis[fa] + 1);
		for(int v : G[u]){
			if(v == fa) continue;
			getdis(v, u);
		}
	}
	void work(){
		while(ttt--){
			cin >> n >> K;
			int ans = INF;
			for(int i = 1, u, v; i < n; i++){
				cin >> u >> v;
				G[u].emplace_back(v);
				G[v].emplace_back(u);
			}
			int U = (1 << n) - 1;
			for(int S = 0; S <= U; S++){
				if(__builtin_popcount(S) != K) continue;
				memset(vis, 0, sizeof(vis));
				for(int i = 0; i < n; i++){
					if(!((S >> i) & 1)) continue;
					vis[i + 1] = 1;
				}
				int cnt = 0;
				memset(dfv, 0, sizeof(dfv));
				for(int i = 1; i <= n; i++)
					if(vis[i] && !dfv[i]) dfs(i, 0), cnt++;
				// cout << cnt << '\n';
				if(cnt > 2) continue;
				memset(dis, 0x3f, sizeof(dis));
				dis[0] = 0;
				for(int i = 1; i <= n; i++)
					if(vis[i]) getdis(i, 0);
				int tmp = 0;
				for(int i = 1; i <= n; i++) tmp = max(tmp, dis[i]);
				ans = min(ans, tmp);
			}
			cout << ans << '\n';
			for(int i = 1; i <= n; i++) G[i].clear();
		}
	}
}


int main(){

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> ysz >> ttt;
	if(ysz <= 3) return sub1::work(), 0;

	return 0;
}