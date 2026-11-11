#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6;
int n, k;
vector<int> g[N + 5];
int fa[N + 5], siz = k, sz[N + 5], d[N + 5], ans, b[55][55];
int Find(int x) {
	return (fa[x] == x ? x : fa[x] = Find(fa[x]));
}
void mer(int x, int y) {
	int xx = Find(x), yy = Find(y);
	if(xx == yy) return;
	fa[xx] = yy;
	if(sz[xx] > 0 && sz[yy] > 0) --siz;
	sz[yy] += sz[xx];
}
void bfs(vector<int> v) {
	queue<int> q;
	for(auto x : v) d[x] = 0, q.push(x);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(auto y : g[x]) {
 			if(d[y] > d[x] + 1) {
				q.push(y); d[y] = d[x] + 1;
			}
		}
	}
	int as = 0; for(int i = 1; i <= n; ++i) as = max(as, d[i]);
	ans = min(ans, as);
}
void solve() {
	cin >> n >> k; 
	ans = n;
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
		b[u][v] = b[v][u] = 1;
	}
	for(int S = 0; S < (1 << n); ++S) {
		if(__builtin_popcount(S) != k) continue;
		for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 0, d[i] = n;
		siz = k;		
		vector<int> v;
		for(int i = 0; i < n; ++i) 
		  if((S >> i) & 1) sz[i + 1] = 1, v.push_back(i + 1);
		for(int i = 0; i < v.size(); ++i) {
			for(int j = i + 1; j < v.size(); ++j)
			if(b[v[i]][v[j]] == 1) mer(v[i], v[j]);
		}
		if(siz > 2) continue;
		bfs(v);
//		for(auto x : v) cout << x << " "; cout << endl;
//		cout <<  ans << endl;
	}
	cout << ans << endl;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
// don't forget change your freopen!!!!!!!!
	int c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
