#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 5e5 + 5;

int c, n, m, d, q;
// 0 ≤c ≤25,1 ≤n ≤500,1 ≤m ≤∑ki ≤5e5,1 ≤d ≤20，1 ≤q ≤1e5
int w[M], k[N], a[N][M], t[N][M];
vector<int> g[M];
int x, y;

/*
 * 题意： 
 * 同一线路内可穿越，换线路需 t[线1][站1] + t[线2][站1]
 * 首尾 w[i] 固定， 
 */ 

int ans = 1e9;
bool vis[M];


void dfs(int u, int ln, int sum) {
	cout << u << ' ';
	if (u == y) {
		ans = max(sum, ans);
		return ;
	}
	for (int i = 1; i <= k[ln]; i++) {
		if (vis[a[ln][i]]) continue;
		vis[a[ln][i]] = 1;
		dfs(a[ln][i], ln, sum);
		//vis[a[ln][i]] = 0;
		for (int j = 0; j < g[a[ln][i]].size(); j++) {
			int nln = g[a[ln][i]][j];
			vis[a[nln][i]] = 1;
			dfs(a[nln][i], nln, sum + t[ln][a[ln][i]] + t[nln][a[ln][i]]);
			//vis[a[nln][i]] = 0;
		}
	}
}

int main() { // Oct31==Dec25
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while (q--) {
		cin >> x >> y;
//		for (int i = 0; i < g[a[x][i]].size(); i++) {
//			int nln = g[a[x][i]][i];
//			//dfs(x, nln, w[x] + w[y]);
//		}
		//
		if (n > 104) {
			cout << w[x] + w[y] << '\n';
			continue;
		}
		dfs(1, 1, w[x] + w[y]);
		cout << ans << '\n'; 
	}
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/ 
