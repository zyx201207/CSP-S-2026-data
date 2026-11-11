#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e6 + 10;
int c, t, n, k;
int maxx, maxp, tot;
int dis[N], vis[N];
int u[N], v[N];
vector<int> g[N];

void dfs1(int pos, int fa){
	dis[pos] = dis[fa] + 1;
	if(dis[pos] > maxx){
		maxx = dis[pos], maxp = pos;
	}
	for(int i = 0;i < g[pos].size();i++){
		int nxt = g[pos][i];
		if(nxt == fa) continue;
		dfs1(nxt, pos);
	}
}
void dfs2(int pos, int fa){
	dis[pos] = dis[fa] + 1;
	tot = max(tot, dis[pos]);
	for(int i = 0;i < g[pos].size();i++){
		int nxt = g[pos][i];
		if(nxt == fa) continue;
		dfs2(nxt, pos);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) g[i].clear();
	for(int i = 1;i < n;i++){
		cin >> u[i] >> v[i];
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	if(k <= 2){
		maxx = maxp = tot = 0;
		for(int i = 1;i <= n;i++) dis[i] = 0;
		dfs1(1, 0);
		for(int i = 1;i <= n;i++) dis[i] = 0;
		dfs2(maxp, 0);
		if(k == 1) cout << tot / 2 << endl;
		else cout << (tot - 1) / 3 << endl;
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
