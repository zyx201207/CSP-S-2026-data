#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 1, inf = INT_MAX;
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9')  {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}
int n, k, rec = 0, ans = inf, cnt = 0;
vector <int> g[maxn];
int vis[maxn], vis2[maxn], res[maxn];
void check(int x) {
	bool f = 0; vis2[x] = 1;
	for(int i : g[x]) {
		if(vis2[i] && vis[i] && vis[x]) f = 1; 
		if(!vis2[i])check(i); 
	}if(!f && vis[x]) cnt++;
}
void dfs2(int x, int st) {
	vis2[x] = 1; if(!vis[x]) res[x] = min(res[x], st);
	for(int i : g[x])
		if(!vis2[i]) dfs2(i, st + 1); 
}
int calc() {
	for(int i = 1;i <= n;i++)
		if(vis[i]) {
			for(int i = 1;i <= n;i++) vis2[i] = 0;
			dfs2(i, 0);	
		} 
	int ca = 0;
	for(int i = 1;i <= n;i++) ca = max(ca, (res[i] == inf ? 0 : res[i]));
	return ca;
}
void dfs(int st) {
	if(rec + n + 1 - st < k) return;
	if(st == n + 1) {
		for(int i = 1;i <= n;i++) vis2[i] = 0; 
		cnt = 0;
		check(1); for(int i = 1;i <= n;i++) res[i] = inf;
		if(rec == k && cnt <= 2) ans = min(ans, calc());
	}
	if(rec < k) {
		vis[st] = 1; rec++;
		dfs(st + 1);
		rec--; vis[st] = 0; 
	} dfs(st + 1); 
} 
void solve() {
	n = read(), k = read(); int m = n / 2; bool gg = 1;
	for(int i = 1;i <= n;i++) g[i].clear(), vis[i] = 0; ans = inf; rec = 0; 
	for(int i = 1, u, v;i < n;i++) {
		u = read(), v = read(), g[u].push_back(v), g[v].push_back(u);
		if((n & 1) && i <= m && u + 1 != v) gg = 0;
		if((n & 1) && i > m && u + m + 1 != v) gg = 0;
	} vis[n] = 0;
	if(n <= 10) { dfs(1); return cout << ans << "\n", void(); }
	else if(n & 1){
		if(gg) cout << max(0ll, (m + 1 - k) / 4 + 1) << "\n";
		else cout << "0\n";
	} else cout << "0\n";
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int _c = read(), t = read();
	_c = 0;
	while(t--) solve();
}

