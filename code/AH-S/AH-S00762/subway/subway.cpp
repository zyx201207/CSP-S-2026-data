#include<bits/stdc++.h>
using namespace std;
const int M = 200010;
long long w[M];
bool vis[M];
struct Line{
	int v, t;
};

vector<vector<Line>> line;
int mincnt;

int c, n, m, d, q;
void dfs(int now, int target, int cnt, int l) {
	if (now == target) {
		mincnt = min(mincnt, cnt);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)line[i].size(); j++) {
			if (line[i][j].v == now) {
				for (int s = 0; s < (int)line[i].size(); s++) {
					if (!vis[line[i][s].v]) {
						vis[line[i][s].v] = true;
						if (i != l) {
							dfs(line[i][s].v, target, cnt + line[i][j].t + line[i][s].t, i);
						} else {
							dfs(line[i][s].v, target, cnt + line[l][s].t, l);
						}
						vis[line[i][s].v] = false;
					}
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	line.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int v, t;
			cin >> v >> t;
			line[i].push_back({v, t});
		}
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = INT_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (int)line[i].size(); j++) {
				if (line[i][j].v == x) {
					mincnt = INT_MAX;
					vis[x] = true;
					dfs(x, y, line[i][j].t, i);
					vis[x] = false;
					mincnt += w[x] + w[y];
					ans = min(ans, mincnt);
				}
			}
		}
		cout << ans << endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
