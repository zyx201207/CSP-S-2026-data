#include <bits/stdc++.h>
clock_t start = clock();
using namespace std;
const int N = 1000005;
vector<int> e[N];
int c, T, n, k, dep[N], ch[N], ans, p[N], nl, nk, cs[N], cnt;
void dfs(int now, int fa){
	dep[now] = dep[fa] + 1;
	cs[++cnt] = now;
	p[now] = fa;
	for (int u : e[now]){
		if (u == fa){
			continue;
		}
		dfs(u, now);
	}
	return;
}
int res, dis[N], vis[N];
void check(){
	queue<int> q;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	res = 0;
	for (int i = 1; i <= n; ++i){
		if (ch[i]){
			q.push(i);
			vis[i] = 1;
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for (int u : e[now]){
			if (vis[u]){
				continue;
			}
			vis[u] = 1;
			dis[u] = dis[now] + 1; 
			res = max(res, dis[u]);
			q.push(u);
		}
	}
	return;
}
void ddd(int now){
	if (now == n + 1 || nk == k){
		if (nk == k){
			res = 0;
			check();
			ans = min(ans, res);			
		}
		return;
	}
	if ((ch[p[cs[now]]] || nl < 2) && nk < k){
		ch[cs[now]] = 1;
		if (!ch[p[cs[now]]]){
			++nl;
		}
		++nk;
		ddd(now + 1);
		--nk;
		if (!ch[p[cs[now]]]){
			--nl; 
		}
	}
	ch[cs[now]] = 0;
	ddd(now + 1);
	return;
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		e[i].clear();
	}
	cnt = 0;
	ans = 0x3f3f3f3f;
	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	ddd(1);
	cout << ans << "\n";
	return;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}

