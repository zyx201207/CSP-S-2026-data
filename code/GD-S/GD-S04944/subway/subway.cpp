//t2 rp += inf
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+10, L = 5e2+10;
ll n,m,d,q,w[N],val[L][L];
struct Line {ll id,w;};
vector<Line> p[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int Tid;
	cin >> Tid >> m >> n >> d >> q;
	for (int i = 1; i <= n; ++i) {
		p[i].emplace_back();
		cin >> w[i];
	}
	for (int i = 1; i <= m; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int u, t;
			cin >> u >> t;
			p[u].push_back((Line){i,t});
		}
	}
	memset(val, 0x3f, sizeof(val));
	for (int i = 1; i <= m; ++i)
		val[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		int sz = p[i].size();
		for (int j = 1; j < sz; ++j) {
			for (int k = 1; k < sz; ++k) {
				int x = p[i][j].id, y = p[i][k].id;
				if (x == y) continue;
				ll res = min(val[x][y], p[i][j].w + p[i][k].w);
				val[y][x] = val[x][y] = res; 
			}
		}
	}
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				val[i][j] = min(val[i][j], val[i][k] + val[k][j]);
			}
		}	
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		ll ans = 9e18;
		int szu = p[u].size(), szv = p[v].size();
		for (int j = 1; j < szu; ++j) {
			for (int k = 1; k < szv; ++k) {
				int x = p[u][j].id, y = p[v][k].id;
				ans = min(ans, val[x][y] + p[u][j].w + p[v][k].w + w[u] + w[v]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
