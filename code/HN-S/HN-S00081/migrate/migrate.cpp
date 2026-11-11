#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5010;
int c, T;
int n, d;
int x[MAXN];
int dis[MAXN][MAXN], cnt[MAXN][MAXN];
vector <int> G[MAXN];
struct node {
	int u, dis;
	bool operator > (const node &a) const {
		return dis > a.dis;
	}
};
bool vis[MAXN];
void dij(int s, int *dis, int *cnt) {
	priority_queue <node, vector <node>, greater <node> > q;
	q.push({s, 0});
	for (int i = 1; i <= n ;i++) {
		dis[i] = 1e18;
		cnt[i] = 0;
		vis[i] = 0;
	}
	dis[s] = 0;
	cnt[s] = 1;
	while (!q.empty()) {
		node x = q.top();
		q.pop();
		int u = x.u;
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : G[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push({v, dis[v]});
			} else if (dis[v] == dis[u] + 1) cnt[v] += cnt[u];
		} 
	}
}
void solve(int c) {
	cin >> n >> d;
	bool flg = 0;
	for (int i = 1; i <= n; i++) cin >> x[i], G[i].clear();
	if (c >= 13 && c <= 14) {
		int cntt = 0;
		for (int i = 1; i <= n; i++)
			if (abs(x[1] - x[i]) <= d && abs(x[i] - x[n]) <= d) cntt++;
		if (cntt > 2) {
			cout << "0\n";
			return;
		}
		if (cntt == 1) {
			cout << "1\n";
			return;
		}
		cout << "1\n";
		return;
	}
	if (c >= 11 && c <= 12) {
		int cha = x[2] - x[1];
		cha = abs(cha);
		d = d / cha * cha;
		if (d < cha) {
			cout << "0\n";
			return;
		}
		if (d == cha) {
			cout << "0\n";
			return;
		}
		int len = (d / cha);
		cout << n - 2 * (d / cha) + 1 << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (abs(x[i] - x[j]) <= d) G[i].push_back(j);
	for (int i = 1; i <= n; i++) dij(i, dis[i], cnt[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (cnt[i][j] == 2) {
				ans++;
//				cout << i << ' ' << j << '\n';
			}
		}
	} 
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		solve(c);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
