#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5200 + 5, INF = 1e18;
int c, T, n, d, x[N], dis[N][N], rd[N], cd[N], vis[N];
vector<pii> e[N];
inline void dij(int s){
	for(int i=0;i<=n;i++){
		dis[s][i] = INF;
	}
	dis[s][s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push({0, s});
	while(!q.empty()){
		auto t = q.top(); q.pop();
		int d = t.fi, u = t.se;
		if(d != dis[s][u]) continue;
		for(auto tmp : e[u]){
			int v = tmp.fi, w = tmp.se;
			if(dis[s][v] > dis[s][u] + w){
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v], v});
			}
		}
	}
}
int dfs(int u, int v, int sum, int mn){
	if(u == v){
		if(sum == mn) return 1;
		return 0;
	}
	if(sum > mn || u > v) return 0;
	int res = 0;
	for(auto t : e[u]){
		int y = t.fi, w = t.se;
		if(vis[y] && y != v) continue;
		res += dfs(y, v, sum + w, mn);
		vis[v] = 1;
	}
	return res;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int s = abs(x[j] - x[i]);
				if(s > d) continue;
				e[i].push_back({j, 1});
				rd[j]++;
				cd[i]++;
			}
		}
//		cout<<"1ok\n";
		for(int i=1;i<=n;i++) dij(i);
		int ans = 0;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j = i + len - 1;
				int mn = dis[i][j];
				if(mn >= INF) continue;
				if(cd[i] < 2 || rd[j] < 2) continue;
				for(int k=0;k<=n;k++) vis[k] = 0; 
				int cnt = 0;
				cnt = dfs(i, j, 0, mn);
				if(cnt == 2){
					ans++;
				}
//				cout<<i<<' '<<j<<' '<<"ok\n";
			}
		}
//		cout<<"2ok\n";
		cout<<ans<<'\n';
		for(int i=0;i<=n;i++){
			e[i].clear(), vis[i] = 0;
			rd[i] = cd[i] = 0;
			for(int j=1;j<=n;j++) dis[i][j] = 0;
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/ 
