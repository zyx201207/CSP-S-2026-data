#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n, k, ans;
int d[N][N];
bool vis[N];
vector<int> num, g[N];
void dfs(int now){
	if(now == k + 1){
		int cnt = 0, tmp = INT_MAX;
		for(int i = 1;i <= n;i ++){
			tmp = INT_MAX;
			if(vis[i]) continue;
			for(auto j : num) tmp = min(tmp, d[i][j]);
			cnt = max(cnt, tmp);
		}
		ans = min(ans, cnt);
		return ;
	}
	for(auto u : num){
		for(auto v : g[u]){
			if(!vis[v]){
				vis[v] = 1;
				num.push_back(v);
				dfs(now + 1);
				vis[v] = 0;
				num.pop_back();
			}
		}
	}
}
void solve(){
	ans = INT_MAX;
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) g[i].clear();
	int u, v;
	memset(d, 0x3f, sizeof d);
	memset(vis, 0, sizeof vis);
	for(int i = 1;i < n;i ++){
		scanf("%d%d", &u, &v);
		d[u][v] = d[v][u] = 1;
		g[u].push_back(v);g[v].push_back(u);
	}
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			num.clear();
			num.push_back(i), num.push_back(j);
			vis[i] = vis[j] = 1;
			dfs(3);
			vis[i] = vis[j] = 0;
		}
	}
	printf("%d\n", ans);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --) solve(); //15pts
	return 0;
}
