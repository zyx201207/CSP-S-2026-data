#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647
using namespace std;

inline int rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

const int N = 2e5 + 5;
vector <int> e[N];
int fa[N], siz[N], dfn[N], dis[N], deg[N];

void dfs(int x) {
	dfn[x] = ++*dfn, siz[x] = 1;
	for(int v : e[x]) if(v != fa[x]) 
		fa[v] = x, dfs(v), siz[x] += siz[v];
}
void solve() {
	int n = rd(), m = rd(), ans = inf; 
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1; i < n; i++) {
		int u = rd(), v = rd();
		e[u].push_back(v), e[v].push_back(u);
	}
	if(m == n) return cout << 0 << '\n', void();
//	for(int i = 1; i <= n; i++) cout << e[i].size() << " \n"[i == n];
	*dfn = 0, dfs(1);
	for(int k = 2; k <= n; k++) {
		for(int i = 1; i <= n; i++) dis[i] = -1;
		queue <int> q;
		vector <int> a, b; a.push_back(0), b.push_back(0);
		for(int i = 1; i <= n; i++) deg[i] = e[i].size() - (i == k) - (i == fa[k]);
		for(int i = 1; i <= n; i++) if(deg[i] == 1) 
			if(dfn[i] >= dfn[k] && dfn[i] <= dfn[k] + siz[k] - 1) q.push(i), dis[i] = 1;
		while(q.size()) {
			int x = q.front(); q.pop();
//			cout << "[1]" << x << ' ' << dis[x] << '\n';
			a.push_back(dis[x]);
			for(int v : e[x]) if(v != fa[k]) {
				dis[v] = max(dis[v], dis[x] + 1);
				if(--deg[v] == 1) q.push(v);
			}
		}
		for(int i = 1; i <= n; i++) if(deg[i] == 1)
			if(dis[i] == -1) q.push(i), dis[i] = 1;
		while(q.size()) {
			int x = q.front(); q.pop();
//			cout << "[2]" << x << ' ' << dis[x] << '\n';
			b.push_back(dis[x]);
			for(int v : e[x]) if(v != k) {
				dis[v] = max(dis[v], dis[x] + 1);
				if(--deg[v] == 1) q.push(v);
			}
		}
		reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
		if(a.size() > b.size()) swap(a, b);
//		for(auto it : a) cout << it << ' '; cout << '\n';
//		for(auto it : b) cout << it << ' '; cout << '\n';
		int len = a.size();
		for(int i = 1; i < min(len, m); i++) ans = min(ans, max(a[i], b[m - i]));
	}
	cout << ans << '\n';
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int TESTID = rd();
	for(int _ = rd(); _--; ) solve();
	return 0;
}
/*

0 1
6 5
1 2
2 5
4 5
5 3
3 6

*/


