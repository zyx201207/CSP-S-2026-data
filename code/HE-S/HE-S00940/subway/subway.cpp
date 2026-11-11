//Oct31==Dec25?
#include <bits/stdc++.h>
#define pii pair <int, int>
#define mp make_pair
#define ll long long

using namespace std;
const int N = 1010;

int C, n, m, d, Q, cnt;
bool vis[N];
ll w[N], c[N][N], dis[N][N], a[N], t[N];

priority_queue <pii, vector <pii>, greater <pii> > q;

void dij (int s) {
	for (int i = 1; i <= m; ++i) vis[i] = 0;
	q.push (mp (0, s)), dis[s][s] = 0;
	while (!q.empty ()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 1; i <= m; ++i) {
			if (i == u || c[u][i] == 1e18) continue;
			if (dis[s][i] > dis[s][u] + c[u][i]) {
				dis[s][i] = dis[s][u] + c[u][i];
				if (!vis[i]) q.push (mp (dis[s][i], i));
			}
		}
	}
}

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d", &C, &n, &m, &d, &Q);
	for (int i = 1; i <= m; ++i) scanf ("%lld", &w[i]);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j) dis[i][j] = c[i][j] = 1e18;
	for (int i = 1; i <= m; ++i) c[i][i] = 0;
	for (int i = 1, k; i <= n; ++i) {
		scanf ("%d", &k);
		for (int j = 1; j <= k; ++j) scanf ("%d%lld", &a[j], &t[j]);
		for (int j = 1; j <= k; ++j)
			for (int o = j + 1; o <= k; ++o) c[a[j]][a[o]] = c[a[o]][a[j]] = min (c[a[j]][a[o]], t[j] + t[o]);
	}
	while (d--) {
		if (cnt >= 1) 
			for (int i = 1; i <= m; ++i)
				for (int j = 1; j <= m; ++j) c[i][j] = dis[i][j];
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= m; ++j) dis[i][j] = 1e18;
		for (int i = 1; i <= m; ++i) dij (i);
		bool flag = 0;
		for (int i = 1; i <= m; ++i) 
			for (int j = 1; j <= m; ++j) if (dis[i][j] != c[i][j]) flag = 1;
		if (!flag) break;
		cnt++;
	} int x, y;
	while (Q--) {
		scanf ("%d%d", &x, &y);
		printf ("%lld\n", w[x] + w[y] + dis[x][y]);
	}
	return 0;
}
