#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int t, n, k, l, r, len, ans, vis[N], fa[N], d[N];
vector<int> G[N];
vector<int> id;
vector<int> s;
void dfs(int now, int f, int deep){
	fa[now] = f;
	d[now] = deep;
	len = max(len, deep);
	for (int v : G[now]){
		if (v == f) continue;
		dfs(v, now, deep + 1);
	}
	if (d[l] < deep) l = now;
	return ;
}
bool ddfs(int now){
	if (now == r){
		id.push_back(r);
		return 1;
	}
	for (int v : G[now]){
		if (v == fa[now]) continue;
		if (ddfs(v)){
			id.push_back(now);
			return 1;
		}
	}
	return 0;
}
int dfss(int now, int x){
	if (!vis[now]) return x;
	return dfss(fa[now], x + 1);
}
queue<int> q;
void bfs(){
	while (!q.empty()){
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for (int v : G[u]){
			if (k <= 0) break;
			if (!vis[v]) continue;
			k--;
			vis[v] = 0;
			q.push(v);
		}
	}
	for (int v : s){
		int num = dfss(v, 0);
		ans = max(ans, num);
	}
	return ;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld", &t);
	scanf("%lld", &t);
	while (t--){
		scanf("%lld", &n);
		scanf("%lld", &k);
		id.clear();
		s.clear();
		for (int i = 1; i <= n; i++){
			G[i].clear();
			vis[i] = -1;
		}
		for (int i = 1; i < n; i++){
			int u, v;
			scanf("%lld", &u);
			scanf("%lld", &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			if (G[i].size() == 1) s.push_back(i);
		}
		dfs(1, 0, 1);
		r = l;
		dfs(l, 0, 1);
		ddfs(l);
		for (int v : id){
			int x = 1.0 * len / 3 + 0.5;
			if (d[v] == x){
				q.push(v);
				vis[v] = 0;
			} else if (d[v] == len - x){
				q.push(v);
				vis[v] = 0;
			}
		}
		bfs();
		printf("%lld\n", ans);
	}
	return 0;
}
