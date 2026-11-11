#include <bits/stdc++.h>
using namespace std;
int n,k,D,vis[1000010],vv[1000010]; vector<int> g[1000010];
void dfs(int now,int pa) {
	if(vv[now] || !vis[now]) return ; vv[now] = 1;
	for(auto v:g[now]) {
		if(v == pa) continue; dfs(v,now);
	}
}
int dd(int now,int pa) {
	int mx = 0; for(auto v:g[now]) {
		if(v == pa || vis[v]) continue;
		mx = max(mx,dd(v,now)+1);
	} return mx;
}
void solve() {
	cin >> n >> k; for(int i = 1; i < n; i++) {
		int u,v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	int ans = 0x3f3f3f3f;
	for(int msk = 0; msk < (1<<n); msk++) {
		if(__builtin_popcount(msk) != k) continue;
		for(int i = 1; i <= n; i++) {
			vis[i] = msk>>(i-1)&1,vv[i] = 0;
		} int p = 0;
		for(int i = 1; i <= n; i++) if(vis[i] && !vv[i]) p++,dfs(i,0);
		if(p == 0 || p > 2) continue;
		int mx = 0; for(int i = 1; i <= n; i++) if(vis[i]) mx = max(mx,dd(i,0));
		ans = min(ans,mx);
	} printf("%d\n",ans);
	for(int i = 1; i <= n; i++) g[i].clear();
}
int main() {
	freopen("hub.in","r",stdin); freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,T; cin >> c >> T; while(T--) solve();
	return 0;
}
