/*
Luogu : PigeonTree
qwq
x x xxx
o o ooo
Expected Points : 100'
*/
#include "bits/stdc++.h"
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define ft first
#define sd second
#define pii pair<int, int>
using namespace std;
const int N = 500 + 5, M = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3fll;
class tempedge {
public :
	int id, v, w;
};
class edge {
public :
	int u, v, w;
};
int c, n, m, q, d;
int w[M], k[N];
vector<tempedge> p[M];
vector<edge> e;
int f[N][N];
auto init() -> void {}
auto solution() -> void {
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) {
		cin >> w[i];
	}
	rep(i, 1, n) {
		cin >> k[i];
		rep(j, 1, k[i]) {
			int ai, ti; cin >> ai >> ti;
			p[ai].push_back({(int)p[ai].size() + 1, i, ti});
		}
	}
	// 线路与线路之间连边？
	rep(i, 1, n) {
		rep(j, 1, n) f[i][j] = INF;
	}
	rep(i, 1, n) f[i][i] = 0;
	rep(i, 1, m) {
		for (auto temp1 : p[i]) {
			for (auto temp2 : p[i]) {
				if (temp1.id == temp2.id) continue;
				f[temp1.v][temp2.v] = min(f[temp1.v][temp2.v], temp1.w + temp2.w);
			}
		}
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		int ans = INF;
		for (auto temp1 : p[u]) {
			for (auto temp2 : p[v]) {
				ans = min(ans, w[u] + w[v] + temp1.w + temp2.w + f[temp1.v][temp2.v]);
			}
		}
		cout << ans << "\n"; 
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
C:\Users\XDFZ\Desktop\down\subway\subway3.out
*/
auto main() -> signed {
//	freopen("subway7.in", "r", stdin);
//	freopen("subway7.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) {
		init();
		solution();
	}
	return 0;
}
