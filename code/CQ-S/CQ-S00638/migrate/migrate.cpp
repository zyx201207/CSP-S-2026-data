/*
Luogu : PigeonTree
qwq
Exoplanetary Mirage
Expected Points : 40'
*/
#include "bits/stdc++.h"
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define ft first
#define sd second
#define pii pair<int, int>
using namespace std;
const int N = 2e6 + 5, INF = 0x3f3f3f3f3f3f3f3fll;
int C;
int n, d;
int a[N];
int far[N], ans;
int dis[N], pre[N];
int vis[N];
auto init() -> void {
	ans = 0;
}
auto solution() -> void {
	cin >> n >> d;
	rep(i, 1, n) {
		cin >> a[i];
	}
	rep(i, 1, n) {
		int l = i, r = n;
		far[i] = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] - a[i] <= d) {
				far[i] = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
	}
	queue<int> q;
	per(i, n, 1) {
		q = queue<int>();
		q.push(i);
		fill(vis + 1, vis + 1 + n, 0);
		fill(dis + 1, dis + 1 + n, INF);
		fill(pre + 1, pre + 1 + n, 0);
		dis[i] = 0, pre[i] = 1;
		while (q.size()) {
			int u = q.front();
//			cout << u << "\n";
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			rep(v, u + 1, far[u]) {
//				cout << u << " -> " << v << " : " << dis[u] + 1 << " " << (dis[v] == INF ? -1 : dis[v]) << "\n";
				if (dis[u] + 1 <= dis[v]) {
					if (dis[u] + 1 == dis[v]) {
						pre[v] += pre[u];
					} else pre[v] = pre[u];
					dis[v] = dis[u] + 1;
//					cout << v << " : " << pre[v] << "\n";
					q.push(v);
				}
			}
		}
//		rep(j, 1, n) {
//			cout << (dis[j] == INF ? -1 : dis[j]) << " ";
//		}
//		cout << "\n";
//		rep(j, 1, n) {
//			cout << pre[j] << " ";
//		}
//		cout << "\n";
		rep(j, i + 1, n) {
			if (pre[j] == 2) ans++;//, cout << i << " ###### " << j << "\n";
		}
	}
	cout << ans << "\n";
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
1 2 4 7 10

0 1
10 3
0 3 6 7 8 9 10 11 14 17
0 3 3 1 1 1 1 1 3 3
*/
auto main() -> signed {
//	freopen("migrate4.in", "r", stdin);
//	freopen("migrate4.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> C >> T;
	while (T--) {
		init();
		solution();
	}
	return 0;
}


