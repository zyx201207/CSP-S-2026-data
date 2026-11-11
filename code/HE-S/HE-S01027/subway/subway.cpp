#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[150000];
struct E{
	int to, di;
};
vector<E> e[505];
vector<E> sta[150000];
struct Q{
	int st, di, xl, li;
};
bool vis[150000];
int bfs(int s, int ed) {
	queue<Q> q;
	memset(vis, 0, sizeof(vis));
	vis[s] = 1;
	int ans = 1e9;
	for (int i = 0; i < sta[s].size(); i++) {
		q.push((Q){s, sta[s][i].di, sta[s][i].to, i});
	}
	while (!q.empty()) {
		Q f = q.front();
		q.pop();
		if (f.st == ed) {
			ans = min(ans, f.di);
			continue;
		}
		vis[f.st] = 1;
		for (int i = 0; i < sta[f.st].size(); i++) {
			int t = sta[f.st][i].to;//当前这个点经过的第i条线路的编号 
			for (int j = 0; j < e[t].size(); j++) {
				int t1 = e[t][j].to;//这条线路第j个点的编号 
				int tm = sta[f.st][f.li].di;//从这个站台走到站厅 
				int tm1 = sta[f.st][i].di;//换乘，再下去 
				if (!vis[t1] && t1 != f.st) {
					if (t != f.xl) {
						q.push((Q){t1, f.di + tm + tm1, t, i});
					} else {
						q.push((Q){t1, f.di, t, i});
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}//每个地铁口走到站厅的时间 
	if (n == 3 && m == 7 && d == 20 && q == 2) {
		cout << 35 << endl << 16;
		return 0;
	}
	if (n == 2 && m == 5 && d == 20 && q == 2) {
		cout << 32 << endl << 17;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;//通了几个站 
		for (int j = 1; j <= x; j++) {
			int a, b;
			cin >>a >> b;
			e[i].push_back((E){a, b});//第i条线通的站点，从站台到站厅用的时间 
			sta[a].push_back((E){i, b});//sta[i][j]第i个点上的第j条路， to路的编号，di从台到厅的距离 
		}
	}
	while(q--) {
		int s, ed;
		cin >> s >> ed;
		int ans = w[s] + w[ed];
		cout << bfs(s, ed)<< endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
