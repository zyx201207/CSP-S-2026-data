#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
const int MAXN = 505, MAXM = 5e5 + 5;
const ll INF = 1e18;

int C, n, m, d, q, u, x, y, k; ll t;
ll w[MAXM], c[MAXN][MAXN], tmp[MAXN][MAXN];
vector<pi> vec[MAXM];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for (int i=1; i<=m; i++) cin >> w[i];
	for (int i=1; i<=n; i++){
		cin >> k;
		for (int j=1; j<=k; j++){
			cin >> u >> t;
			vec[u].pb({i, t});
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (i == j) c[i][j] = 0;
			else c[i][j] = INF;
		}
	}
	for (int i=1; i<=m; i++){
		int sz = vec[i].size();
		for (int j=0; j<sz; j++){
			for (int k=j+1; k<sz; k++){
				int u = vec[i][j].fi, v = vec[i][k].fi;
				ll w = vec[i][j].se + vec[i][k].se;
				c[u][v] = min(c[u][v], w), c[v][u] = min(c[v][u], w);
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) for (int k=1; k<=n; k++) tmp[j][k] = c[j][k];
		for (int j=1; j<=n; j++) for (int k=1; k<=n; k++) c[j][k] = min(c[j][k], tmp[j][i] + tmp[i][k]);
	}
	for (int i=1; i<=q; i++){
		cin >> x >> y;
		ll ans = INF;
		int sz1 = vec[x].size(), sz2 = vec[y].size();
		for (int j=0; j<sz1; j++){
			for (int k=0; k<sz2; k++){
				int u = vec[x][j].fi, v = vec[y][k].fi;
				ll w = vec[x][j].se + vec[y][k].se;
				ans = min(ans, c[u][v] + w);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}