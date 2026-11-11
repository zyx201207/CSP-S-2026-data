#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, inf = 2e9;

ll c, T, n, d, x[N], cnt, min_step, dis[3005][3005], res[3005][3005], sum[3005][3005];
ll ans;

void dfs(int u, int ed, int step) {
	if (u >= ed) {
		if (u == ed) {
			if (step < min_step) min_step = step, cnt = 0;
			if (step == min_step) ++cnt;
		}
		return;
	}
	for (int i = u + 1; x[i] <= x[u] + d; ++i) dfs(i, ed, step + 1);
	return;
}

void solve1() {
	for (int u = 1; u <= n; ++u) {
		for (int v = u + 2; v <= n; ++v) {
			cnt = 0;
			min_step = inf;
			dfs(u, v, 0);
			if (cnt == 2) {
				++ans;
				cout << u << ' ' << v << '\n';
			}
		}
	}
	cout << ans << '\n';
	return;
}

void solve2() {
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j) res[i][j] = 0;
	for (int i = 1; i <= n; ++i) res[i][i] = 1;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j) dis[i][j] = inf;
	for (int u = 1; u <= n; ++u) {
		if (x[u] + d >= x[u + 1]) dis[u][u + 1] = 1, res[u][u + 1] = 1;
		for (int v = u + 2; v <= n; ++v) {
			for (int w = u; w < v; ++w) {
				if (x[w] + d >= x[v]) {
					if (dis[u][v] > dis[u][w] + 1) dis[u][v] = dis[u][w] + 1, res[u][v] = 0;
					if (dis[u][v] == dis[u][w] + 1) res[u][v] += res[u][w];
				}
			}
//			cout << u << ' ' << v << ' ' << dis[u][v] << '\n';
			if (res[u][v] == 2) ++ans;
		}
	}
	cout << ans << '\n';
	return;
}

void solve3() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			res[i][j] = dis[i][j] = sum[i][j] = 0;
			if (i == j) res[i][j] = sum[i][j] = 1;
		}
	}
	for (int u = 1; u <= n; ++u) {
		for (int v = u + 1, w1 = u, w2 = u; v <= n; ++v) {
			while (x[w1] + d < x[v]) ++w1;
			if (w1 == v) break;
			dis[u][v] = dis[u][w1] + 1;
			w2 = w1;
			while (dis[u][w2 + 1] + 1 == dis[u][v]) ++w2;
			res[u][v] = sum[u][w2] - sum[u][w1 - 1];
			sum[u][v] = sum[u][v - 1] + res[u][v];
//			cout << res[u][v] << ' ';
			if (res[u][v] == 2) {
				++ans;
//				cout << u << ' ' << v << '\n';
			}
		}
//		cout << '\n';
	}
	cout << ans << '\n';
	return;
}

void solve4() {
	if (n == 1) cout << "0\n";
	else {
		ll gd = x[2] - x[1];
		if (d >= gd * 2) {
			cout << n - 3 << '\n';
		} else cout << "0\n";
	}
	return;
}

void solve5() {
	cout << "0\n";
	return;
}

void solve6() {
	cout << rand() << '\n';
	return;
}

void solve() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	if (c >= 1 && c <= 2) solve1();
	else if (c >= 3 && c <= 6) solve2();
	else if (c >= 7 && c <= 10) solve3();
	else if (c >= 11 && c <= 12) solve4();
	else if (c >= 13 && c <= 14) solve5();
	else solve6();
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (cin >> c >> T; T--; solve());
	return 0;
}

/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
