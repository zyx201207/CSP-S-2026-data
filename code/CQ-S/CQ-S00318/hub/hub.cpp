#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define eb emplace_back
#define PII pair<int, int>
#define mse(x, y) memset(x, y, sizeof(x))
#define mcp(x, y) memcpy(x, y, sizeof(x))
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

namespace bf1{
	const int MAXN = 15, MAXK = 15;
	int n, k, ans, dis[MAXN];
	bool vis[MAXN];
	vector<int> G[MAXN];
	
	void dfs(int u, int msk){
		if(vis[u]) return ;
		vis[u] = 1;
		for(auto v : G[u]) if((msk & (1 << v - 1))) dfs(v, msk);
	}
	
	void Getdis(int u){ for(auto v : G[u]) if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, Getdis(v); }
	
	void Main(){
		cin >> n >> k,ans = 0x3f3f3f3f3f3f3f3f;
		rep(i, 1, n) G[i].clear();
		rep(i, 2, n){
			int u, v;
			cin >> u >> v, G[u].pb(v), G[v].pb(u);
		}
		rep(msk, 0, (1 << n) - 1){
			int num = 0;
			rep(i, 1, n) num += (bool)(msk & (1 << i - 1));
			if(num != k) continue;
			num = 0;
			mse(vis, 0);
			rep(i, 1, n) if((msk & (1 << i - 1)) && !vis[i]) num++, dfs(i, msk);
			if(num > 2) continue;
			mse(dis, 0x3f);
			rep(i, 1, n) if((msk & (1 << i - 1))) dis[i] = 0, Getdis(i);
			int Max = 0;
			rep(i, 1, n) Max = max(Max, dis[i]);
			ans = min(ans, Max);
		}
		cout << ans << '\n';
	}
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	FASTIO;
	int C, T;
	cin >> C >> T;
	rep(i, 1, T) bf1::Main();
	return 0;
}
