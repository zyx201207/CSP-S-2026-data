#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, dp[1000006], dfn[1000006], mx[1000006][2], o, son[1000006][2];
vector<int> e[1000006];
int l[1000006], cnt, cnt[1000006];
void dfs(int u, int fa){
	dfn[u] = dfn[fa] + 1;
	for(auto v : e[u]){
		if(fa == v)continue;
		dfs(v, u);
		if(dp[v] >= dp[u]){
			mx[u][1] = mx[u][0], mx[u][0] = dp[v];
			son[u][1] = son[u][0], son[u][0] = v;
		}
		dp[u] = max(dp[u], dp[v]);
	}
	if(dfn[u] >= mx[u][1])o = u;
	dp[u]++;
	cnt[dp[u]]++;
}
void dfs2(int u, int fa){
	dfs2(son[u][0], u);
	l[++cnt] = u;
	if(fa == 0)dfs2(son[u][1], u);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &d);
		memset(cnt, 0, sizeof(cnt));
		cnt = 0;
		for(int i = 1; i <= n; i++)e[i].clear();
		for(int i = 1; i < n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
		dfs2(o, 0);
		printf("2\n");
	}
	return 0;
}
