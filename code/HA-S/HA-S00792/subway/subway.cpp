#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define qep(i, a, b) for(int i = (a); i >= (b); i --)
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define int long long
using namespace std;

const int N = 500010;
const int INF = 1e18;
vector <pii> v[N];
int dis[505][505], w[N];
int n, m, d, Q;

void add(int u, int v, int w) {
	dis[u][v] = min(dis[u][v], w);
	dis[v][u] = min(dis[v][u], w);	
}

void floyd() {
	rep(i, 1, n) {
		rep(j, 1, n) {
			rep(k, 1, n) {
				if(dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

void solution() {
	cin >> n >> m >> d >> Q;
	rep(i, 1, n) rep(j, 1, n) {
		if(i == j) dis[i][j] = 0;
		else dis[i][j] = INF;
	}
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int k; cin >> k;
		rep(j, 1, k) {
			int x, y; cin >> x >> y;
			v[x].pb({y, i});
		}
	}
	rep(i, 1, m) {
		int sz = v[i].size();
		rep(j, 0, sz - 1) {
			rep(k, 0, sz - 1) {
				int x = v[i][j].se, y = v[i][k].se;
				int w = v[i][j].fi + v[i][k].fi;
				add(x, y, w);
			}
		}
	}
	floyd();
//	cout << (fd(123) == fd(131)) << '\n';
//	cout << dis[14][15] << '\n';
//	rep(i, 1, n) {
//		rep(j, 1, n) cout << dis[i][j] << ' ';
//		cout << '\n';
//	}
	while(Q --) {
		int x, y; cin >> x >> y;
		int res = INF;
		for(pii &i : v[x]) for(pii &j : v[y]) {
//			cout << i.se << ' ' << j.se << '\n';
			res = min(res, i.fi + j.fi + dis[i.se][j.se]);
		}
//		cout << res << '\n';
		cout << res + w[x] + w[y] << '\n';
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C; cin >> C;
	solution();
	return 0;
}
/*
fc /W subway7.ans subway.out
0 1 2 0 1
1 1
2 1 2 2 3
1 2
*/

