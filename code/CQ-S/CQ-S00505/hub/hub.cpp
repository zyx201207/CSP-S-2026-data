#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n, k, ma, ans, x[N], y[N], f[N], cn[N], mx[N], dep[N];
vector<int> q[N];
inline void dfs(int u, int v, int id){
	if(dep[u] > dep[ma]) ma = u;
	f[u] = v;
	for(int to : q[u]){
		int step = x[to] + y[to] - u;
		if(to == id || step == v) continue;
		dep[step] = dep[u] + 1, dfs(step, u, id);
	}
	return ;
}
inline void got(int u, int v, int id){
	mx[u] = 0;
	for(int to : q[u]){
		int step = x[to] + y[to] - u;
		if(to == id || step == v) continue;
		got(step, u, id), mx[u] = max(mx[u], mx[step] + 1);
	}
	cn[v == 0 ? n : mx[u]] ++;
	return ;
}
inline void sol(int x, int id){
	ma = 0, dep[x] = 1, dfs(x, 0, id);
	int step = ma;
	ma = 0, dep[step] = 1, dfs(step, 0, id);
	for(int len = (dep[ma] >> 1);len > 0;len = ~-len) ma = f[ma];
	got(ma, 0, id);
	return ;
}
inline void solve(){
	cin>>n>>k, ans = n, x[0] = y[0] = 1;
	for(int i = 1;i <= n;i = -~i) q[i].clear();
	for(int i = 1;i < n;i = -~i) cin>>x[i]>>y[i], q[x[i]].emplace_back(i), q[y[i]].emplace_back(i);
	for(int i = 0;i < n;i = -~i){
		for(int j = 0;j <= n;j = -~j) cn[j] = 0;
		sol(x[i], i);
		if(i != 0) sol(y[i], i);
		int sum = 0, now = n + 1;
		while(now != 0 && sum + cn[now - 1] <= k) now --, sum += cn[now];
		ans = min(ans, now);
	} 
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t --) solve(); 
	return 0;
} 
