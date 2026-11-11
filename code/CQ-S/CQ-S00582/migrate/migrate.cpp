#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 5e3 + 5, INF = 1e18;
int op, T, n, d, a[MAXN], lst[MAXN], len, dis[MAXN], cnt[MAXN];

struct Node {
	int x, y, z, nxt;
}ls[MAXN * MAXN];

void add(int x, int y, int z) {
	ls[++len].x = x, ls[len].y = y, ls[len].z = z, ls[len].nxt = lst[x], lst[x] = len;
}

int ans = 0;

struct P {
	int x, dis;
	P (int _x, int _dis) {
		x = _x, dis = _dis; 
	}
};

bool operator < (P a, P b) {
	return a.dis > b.dis;
}

priority_queue<P> pq;

void dij(int S) {
	for (int i = 1; i <= n; i++) dis[i] = INF, cnt[i] = 0;
	dis[S] = 0, cnt[S] = 1, pq.push(P(S, 0));
	while (!pq.empty()) {
		P t = pq.top(); pq.pop();
		for (int j = lst[t.x]; j; j = ls[j].nxt) {
			int y = ls[j].y;
			if (dis[y] > dis[t.x] + ls[j].z) {
				dis[y] = dis[t.x] + ls[j].z, cnt[y] = cnt[t.x];
//				if (y == 2) cout << "CJMK " << cnt[y] << ' ' << t.x << '\n';
				pq.push(P(y, dis[y]));
			} else if (dis[y] == dis[t.x] + ls[j].z) cnt[y] += cnt[t.x];
		}
	}
//	cout << cnt[2] << ' ';
	for (int i = 1; i <= n; i++) if (cnt[i] == 2) ans ++;
//	cout << S << ' ' << ans << '\n';
}

void solve() {
//	cout << "CJMK" << '\n';
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i], lst[i] = 0;
	int c = a[2] - a[1];
//	cout << n << ' ' << d << ' ' << c << '\n'; 
	if (op == 11 || op == 12) {
		if (d / c < 2) cout << 0 << '\n';
		else cout << max(0LL, n - d / c * 2 + 1) << '\n';
		return;
	}
	len = ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[i] > d) break;
//			cout << i << ' ' << j << '\n';
			add(i, j, 1), add(j, i, 1);
		}
	}
	for (int i = 1; i <= n; i++) dij(i);
	cout << ans / 2 << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> op >> T;
	while (T--) solve();
	return 0;
}
/*
1 1
5 2
1 2 3 4 5
*/
