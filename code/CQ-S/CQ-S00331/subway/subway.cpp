#include<bits/stdc++.h>
#define qaq ios::sync_with_stdio(0), cin.tie(0)
#define lb(x) (x&(-x))
#define PII pair<int,ll>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a,b) for(int i=(a);i>=(b);--i)
#define debug(x) cout << #x << "=" << x << " "
using namespace std;
typedef long long ll;
const int N = 5e5+10, M = 505;
ll a[N];
vector<PII> g[N];
ll f[M][M];
int _,n,m,d,q;
int main() {
	qaq;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> _ >> m >> n >> d >> q;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) {
		int k; cin >> k;
		while(k --) {
			int u; ll ww; cin >> u >> ww;
			g[u].emplace_back(i, ww);
		}
	}
	memset(f, 0x3f, sizeof f);
	rep(i, 1, m) f[i][i] = 0;
	rep(i, 1, n) {
		int o = g[i].size();
		rep(j, 0, o-1) {
			int p = g[i][j].first; ll w = g[i][j].second;
			rep(jj, j+1, o-1) {
				int pp = g[i][jj].first; ll ww = g[i][jj].second;
				f[p][pp] = min(f[p][pp], w+ww), f[pp][p] = f[p][pp];
			}
		}
	}
	rep(k, 1, m) {
		rep(i, 1, m) {
			rep(j, 1, m) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		}
	}
	while(q --) {
		int u,v; cin >> u >> v;
		ll ans = 4557430888798830399;
		for(PII ti : g[u]) {
			int pu = ti.first; ll wu = ti.second;
			for(PII tj : g[v]) {
				int pv = tj.first; ll wv = tj.second;
				ans = min(ans, a[u] + wu + a[v] + wv + f[pu][pv]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}




