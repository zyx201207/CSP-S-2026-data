#include <bits/stdc++.h>
using namespace std;
int n, k, u, v, sum[1000005], fa[1000005], dep[1000005], mx, len[1000005];
vector<int> e[1000005];
void dfs(int u){
	if(dep[u] > dep[mx]) mx = u;
	int sz = e[u].size();
	for(int i = 0;i < sz;i++){
		int v = e[u][i];
		if(!v || v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}
void _dfs(int u){
	len[u] = 1;
	int sz = e[u].size();
	for(int i = 0;i < sz;i++){
		int v = e[u][i];
		if(!v || v == fa[u]) continue;
		fa[v] = u;
		_dfs(v);
		len[u] = max(len[u], len[v] + 1);
	}
	sum[len[u]]++;
}
int solve_m(int x, int y){
	for(int i = 1;i <= n;i++) sum[i] = 0;
	dep[x] = fa[x] = 0;
	mx = x;
	dfs(x);
	fa[mx] = dep[mx] = 0;
	dfs(mx);
	int t = dep[mx] / 2;
	while(t--) mx = fa[mx];
	fa[mx] = 0;
	_dfs(mx);
	dep[y] = fa[y] = 0;
	mx = y;
	dfs(y);
	fa[mx] = dep[mx] = 0;
	dfs(mx);
	t = dep[mx] / 2;
	while(t--) mx = fa[mx];
	fa[mx] = 0;
	_dfs(mx);
	int s = 0;
	for(int i = n;i >= 1;i--){
		s += sum[i];
		if(s > k) return i;
	}
	return 0;
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) e[i].clear();
	for(int i = 1;i <= n - 1;i++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = n + 1;
	for(int i = 1;i <= n;i++){
		int sz = e[i].size();
		for(int j = 0;j < sz;j++){
			int k = e[i][j];
			if(k < i) continue;
			e[i][j] = 0;
			int sz1 = e[k].size();
			for(int l = 0;l < sz1;l++){
				if(e[k][l] == i){
					e[k][l] = 0;
					ans = min(ans, solve_m(i, k));
					e[k][l] = i;
					break;
				}
			}
			e[i][j] = k;
		}
	}
	cout << ans << endl;
}
int c, t;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
