#include<bits/stdc++.h>
#define int long long
#define INF 1e17
using namespace std;

const int N = 2e6 + 10;

int c, T;
int n, k, ans;
vector<int> G[N];

int vis[N], d[N], dis[N];
void dfs(int u, int fa){
	for(auto v : G[u]){
		if(v == fa) continue;
		if(vis[v] || !d[v]) continue;
		vis[v] = 1;
		dfs(v, u);
	}
}
bool check_block(int s){
	int CNT = 0;
	for(int i = 0; i < n; ++i) d[i + 1] = ((s >> i) & 1), vis[i + 1] = 0;
	for(int i = 1; i <= n; ++i){
		if(vis[i] || !d[i]) continue;
		if(++CNT > 2) return 0;
		dfs(i, 0);
	}
	return 1;
}
int bfs(){
	int res = -INF;
	queue<int> q;
	for(int i = 1; i <= n; ++i) vis[i] = 0, dis[i] = INF;
	for(int i = 1; i <= n; ++i) if(d[i]) q.push(i), vis[i] = 1, dis[i] = 0;
	while(q.size()){
		int u = q.front(); q.pop();
		for(auto v : G[u]){
			if(vis[v]) continue;
			vis[v] = 1;
			dis[v] = min(dis[v], dis[u] + 1);
			q.push(v);
		}
	}
	for(int i = 1; i <= n; ++i) res = max(res, dis[i]);
	return res;
}

int rt, ed, F[N];
void dfs1(int u, int fa){
	for(auto v : G[u]){
		if(v == fa) continue;
		dis[v] = dis[u] + 1;
		dfs1(v, u);
	}
	if(dis[u] > dis[rt]) rt = u;
}
void dfs2(int u, int fa){
	F[u] = fa;
	for(auto v : G[u]){
		if(v == fa) continue;
		dis[v] = dis[u] + 1;
		dfs2(v, u);
	}
	if(dis[u] > dis[ed]) ed = u;
}

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	for(int i = 1; i <= n; ++i) G[i].clear();
	
	n = read(), k = read();
	for(int i = 1; i < n; ++i){
		int u = read(), v = read();
		G[u].push_back(v), G[v].push_back(u);
	}
	if(1 <= c && c <= 3){
		ans = INF;
		for(int s = 0; s < (1 << n); ++s){
			if(__builtin_popcount(s) != k) continue;
			if(!check_block(s)) continue;
			ans = min(ans, bfs());
		}
		printf("%lld\n", ans);
		return;
	}
	if(k == 1 || k == 2){
		dfs1(1, 0);
		dis[rt] = 0, dfs2(rt, 0);
		int t = dis[ed], u = ed, v;
		for(int i = 1; i <= t / 2; ++i) u = F[u];
		d[u] = 1;
		if(k == 2) v = F[u], d[v] = 1;
		ans = bfs();
		printf("%lld\n", ans);
		return;
	}
	
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), T = read();
	while(T--) solve();
	return 0;
}

/*
枚举方案
暴力判断
C(n,k) * n


k = 1,2 
找树的直径 的中点



0 2
5 2
1 2
2 3
3 4
4 5
10 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
5 2
1 2
2 3
3 4
2 5
*/
