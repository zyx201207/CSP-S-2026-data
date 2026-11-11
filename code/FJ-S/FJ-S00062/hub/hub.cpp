#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 1e6 + 5;

int n, k, c, h[N], p[N], fa[N][25], lg[N], dis[N], dp1[N], dp2[N];
vector<int> g[N];
bool isHub[N], vis[N];

void dfs(int x) {
	for(int i = 1; i <= lg[dp2[x]]; i++) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	} 
	for(int y : g[x]) {
		if(y == p[x]) continue;
		p[y] = x;
		dp2[y] = dp2[x] + 1;
		dfs(y);
	}
}

bool check() { 
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(isHub[i] && !isHub[p[i]]) ++cnt;
		if(cnt > 2) return false;
	}
	return true;
} 

void dfs2(int x) {
	for(int y : g[x]) {
		if(y == p[x]) continue;
		dfs2(y);
		dp1[x] = max(dp1[x], dp1[y] + 1);
	}
}
//rp++
int lca(int u, int v) {
	int pp = u, q = v;
	if(dp2[pp] < dp2[q]) swap(pp, q);
	while(dp2[pp] > dp2[q]) {
		pp = fa[pp][lg[dp2[pp] - dp2[q]]];
	}
	if(pp == q) return pp;
	for(int i = lg[dp2[pp]]; i >= 0; i--) {
		if(fa[pp][i] != fa[q][i]) {
			pp = fa[pp][i], q = fa[q][i];
		}
	}
	return fa[pp][0];
}

// to be continued: A & k=2

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1);
	if(c <= 3) { // O(nk2^n)
		int ans = 0x3f3f3f3f;
		for(int i = 1; i < (1 << n); i++) {
			if(__builtin_popcount(i) != k) continue;
			queue<pii> q;
			for(int j = 0, num = 0; j < n; j++) {
				if((i >> j) & 1) {
					h[++num] = j + 1, isHub[j + 1] = true, dis[j + 1] = 0, vis[j + 1] = true;
					q.push({j + 1, 0});
				} else isHub[j + 1] = false, dis[j + 1] = 0x3f3f3f3f, vis[j + 1] = false;
			}
			if(!check()) continue;
			while(!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for(int z : g[x]) {
					if(!vis[z]) {
						dis[z] = y + 1, vis[z] = true; q.push({z, dis[z]});
					}
				}
			}
			int D = 0;
			for(int j = 1; j <= n; j++) {
				D = max(D, dis[j]);
			}
			ans = min(ans, D);
		}
		cout << ans << endl;
	} else if(c == 13 || c == 14) { // ÐÔÖÊA 
		if(k <= n / 2) {
			cout << (n / 2 + 1 - k) / 3 + 1 << endl; 
		} else if(k < n) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	} else if(c == 7 || c == 11 || c == 12) {
		int ans = 0x3f3f3f3f;
		dfs2(1);
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int LCA = lca(i, j);
				if(LCA == i) {
					ans = min(ans, max({dp2[i], (dp2[j] - dp2[i] + 1) / 2, min(dp1[i], dp1[j])}));
				} else if(LCA == j) {
					ans = min(ans, max({dp2[j], (dp2[i] - dp2[j] + 1) / 2, min(dp1[i], dp1[j])}));
				} else ans = min(ans, max(max(dp1[i], dp2[i]), max(dp1[j], dp2[j])));
			}
		}
		cout << ans << endl;
	} else {
		int ans = 0x3f3f3f3f;
		for(int i = 1; i < (1 << n); i++) {
			if(__builtin_popcount(i) != k) continue;
			queue<pii> q;
			for(int j = 0, num = 0; j < n; j++) {
				if((i >> j) & 1) {
					h[++num] = j + 1, isHub[j + 1] = true, dis[j + 1] = 0, vis[j + 1] = true;
					q.push({j + 1, 0});
				} else isHub[j + 1] = false, dis[j + 1] = 0x3f3f3f3f, vis[j + 1] = false;
			}
			if(!check()) continue;
			while(!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for(int z : g[x]) {
					if(!vis[z]) {
						dis[z] = y + 1, vis[z] = true; q.push({z, dis[z]});
					}
				}
			}
			int D = 0;
			for(int j = 1; j <= n; j++) {
				D = max(D, dis[j]);
			}
			ans = min(ans, D);
		}
		cout << ans << endl;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for(int i = 2; i <= 1000000; i++) lg[i] = lg[i >> 1] + 1;

	int T = 1;
	cin >> c >> T;
	while(T--) solve();

	return 0;
}

