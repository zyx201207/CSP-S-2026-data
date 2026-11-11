#include<bits/stdc++.h>
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) (A).begin(), (A).end()
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using i64 = long long;
template<typename T> inline void cmax(T &x, const T &y) { x = (x < y ? y : x); }
template<typename T> inline void cmin(T &x, const T &y) { x = (x < y ? x : y); }
const int N = 505, M = 5e5 + 5;
i64 dis[N][N];
int w[M], tsk_id, n, m, q, D;
vector<pii> vec[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fastio, cin >> tsk_id >> n >> m >> D >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n) {
		int k; cin >> k;
		rep(j, 1, k) {
			int x, y;
			cin >> x >> y;
			vec[x].pb({y, i});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, m) {
		for(const auto &x : vec[i]) {
			for(const auto &y : vec[i]) {
				i64 v = x.fi + y.fi;
				cmin(dis[x.se][y.se], v);
			}
		}
	}
	rep(k, 1, n) rep(i, 1, n) if(dis[i][k] < 1e18) rep(j, 1, n)
		cmin(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
		int x, y;
		cin >> x >> y;
		i64 ans = 1e18;
		for(const auto &p : vec[x]) {
			for(const auto &q : vec[y]) {
				cmin(ans, dis[p.se][q.se] + p.fi + q.fi);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
