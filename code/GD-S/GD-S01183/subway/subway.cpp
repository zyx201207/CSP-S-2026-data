#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll inf = 1e16 + 7;
const int N = 5e2 + 7;
const int M = 5e5 + 7;

int cid, n, m, d, q, len[N];
vector<int> a[N], t[N];
struct node {
	ll to, w;
} ;
vector<node> G[M];

ll f[N][N], w[M];

int main() {
//	system("fc subway6.ans subway.out");
//	return 0;
//	subway
//	freopen("subway6.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> cid >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> len[i];
		for(int j = 1; j <= len[i]; j++) {
			int in1, in2;
			cin >> in1 >> in2;
			a[i].pb(in1), t[i].pb(in2);
			G[in1].pb({i, in2});
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j] = inf;
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < (int)G[i].size(); j++) {
			for(int k = j + 1; k < (int)G[i].size(); k++) {
				f[G[i][j].to][G[i][k].to] = min(G[i][j].w + G[i][k].w, f[G[i][j].to][G[i][k].to]);
				f[G[i][k].to][G[i][j].to] = min(G[i][j].w + G[i][k].w, f[G[i][k].to][G[i][j].to]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		f[i][i] = 0;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
			}
		}
	}
	for(int i = 1, st, ed; i <= q; i++) {
		ll ans = inf;
		cin >> st >> ed;
		for(int j = 0; j < (int)G[st].size(); j++) {
			for(int k = 0; k < (int)G[ed].size(); k++) {
				ans = min(ans, f[G[st][j].to][G[ed][k].to] + w[st] + w[ed] + G[st][j].w + G[ed][k].w);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
