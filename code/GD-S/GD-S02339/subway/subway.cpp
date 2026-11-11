#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int w[N], a[501][501], t[501][501], k[N], x[N], y[N], t1[N][N];
int mint = N;
bool flag[N];
void dfs(int station, int goal, int time) {
	if (flag[station] || k[station] == 0) return;
	if (station == goal) {
		mint = min(time + w[goal], mint);
		return;
	}
	flag[station] = true;
	for (int i = 1; i <= k[station]; i++) {
		if (i == 1) dfs(a[station][i], goal, time + t[station][i]);
		else dfs(a[station][i], goal, time + t1[station][i]);
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	} 
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			t1[i][j] = t1[i][j - 1] + t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		memset(flag, 0, sizeof(flag));
		cin >> x[i] >> y[i];
		if (x[i] == y[i]) cout << 0 << endl;
		else dfs(x[i], y[i], w[x[i]]);
		cout << mint << endl;
		mint = N;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
