#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, x, y;
int read() {
	int f = 1, x = 0;
	char ch = ' ';
	while(ch < '0' || ch > '9') {
		ch = getchar();
		if(ch == '-') f = -1;
	}
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return f * x;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(); n = read(); m = read(); d = read(); q = read();
	vector<int> w(m + 1), k(n + 1);
	vector<vector<int>> t(m + 1),
		dis(n + 1, vector<int>(n + 1, 0x3f3f3f3f3f3f3f3f)), bepassed(m + 1);
	for(int i = 1; i <= m; ++ i) w[i] = read();
	for(int i = 1; i <= n; ++ i) {
		k[i] = read();
		for(int j = 1, A, T; j <= k[i]; ++ j) {
			A = read(); T = read();
			bepassed[A].push_back(i);
			t[A].push_back(T);
		}
	}
	for(int i = 1; i <= n; ++ i)
		dis[i][i] = 0;
	for(int i = 1; i <= m; ++ i) {
		for(int j = 0; j < bepassed[i].size() - 1; ++ j) {
			for(int k = j + 1; k < bepassed[i].size(); ++ k) {
				dis[bepassed[i][j]][bepassed[i][k]] = dis[bepassed[i][k]][bepassed[i][j]]
					= min(dis[bepassed[i][j]][bepassed[i][k]], t[i][j] + t[i][k]);
			}
		}
	}
	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i < n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q --) {
		cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(int s = 0; s < bepassed[x].size(); ++ s)
			for(int e = 0; e < bepassed[y].size(); ++ e) {
				ans = min(ans, dis[bepassed[x][s]][bepassed[y][e]]
					+ w[x] + w[y] + t[x][s] + t[y][e]);
			}
		
//		cout << bepassed[x].size() << ',' << bepassed[y].size() << '\n';
		
		cout << ans << '\n';
	}
//	cout << dis[1][2] << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
