#include <bits/stdc++.h>
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
using namespace std;
using ll = long long;
const int N = 100 + 10;


int n, k;
vector<int> g[N];
int fa[N], vis[N];
int dis[N][N];
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]); 
}
void solve() {
	cin >> n >> k;
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; ++i) dis[i][i] = 0, g[i].clear();
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				cmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	cerr << "  fuck\n";
	int rsj = 7891;
	for(int s = 0; s < (1 << n); ++s) {
//		cerr << s << "   rrrs\n";
		int cnt = 0, tmp = s;
		while(tmp) cnt += (tmp & 1), tmp >>= 1;
		if(cnt != k) continue;
		for(int i = 1; i <= n; ++i) fa[i] = i, vis[i] = 0;
		for(int i = 1; i <= n; ++i) {
			if(s & (1 << i - 1)) {
				for(auto v : g[i]) {
					if(s & (1 << v - 1)) {
						fa[find(v)] = fa[find(i)];
					}
				}
			}
		}
		cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(!vis[find(i)] && (s & (1 << i - 1))) {
				++cnt;
				vis[find(i)] = 1;
			}
		}
		if(cnt > 2) continue;
		
		cnt = 0;
		for(int i = 1; i <= n; ++i) {
			int tmp = 114514;
			for(int j = 1; j <= n; ++j) {
				if((s & (1 << j - 1))) {
					cmin(tmp, dis[i][j]);
				}
			}
			cmax(cnt, tmp);
		}
		cmin(rsj, cnt);
	}
	cout << rsj << "\n";
	return ;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
} 
