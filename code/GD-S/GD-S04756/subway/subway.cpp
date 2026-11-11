#include <bits/stdc++.h>
using namespace std;
struct SubwayStation {
	int a, t, c;
};
int c, n, d, m, q; // n: line_cnt, m: station_cnt
vector<int> w, k;
vector<vector<SubwayStation>> at;
const int INF = 0x3f3f3f3f;
int ks = 0;
void brute() {
	int cntt = m;
	vector<vector<int>> g(m + ks + 1, vector<int>(m + ks + 1, INF));
	vector<vector<int>> fl(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			cntt++;
			int nd = cntt;
			g[at[i][j].a][nd] = g[nd][at[i][j].a] = at[i][j].t;
			at[i][j].c = nd;
		}
		for (int j = 2; j <= k[i]; j++)
			g[at[i][j].c][at[i][j - 1].c] = g[at[i][j - 1].c][at[i][j].c] = 0;
	}
	for (int kk = 1; kk <= cntt; kk++)
		for (int i = 1; i <= cntt; i++)
			for (int j = 1; j <= cntt; j++)
				if (g[i][kk] != INF && g[kk][j] != INF)
					g[i][j] = min(g[i][j], g[i][kk] + g[kk][j]); 
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + g[x][y] << endl;
	}
}
struct State {
	int cst, nd, lnn;
};
vector<vector<pair<int,int>>> InLine;
void specialB() {
	InLine.resize(m + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			InLine[at[i][j].a].push_back({i,j});
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		queue<State> pq;
		for (auto z:InLine[x])
			pq.push({0,x,z.first});
		vector<int> dis(n + 1, INF);
		vector<bool> vis(n + 1, false);
		dis[x] = 0;
		int res = 0;
		while(!pq.empty()) {
			State p = pq.front();
			pq.pop();
//			cerr << "ER: " << p.nd << " " << p.lnn << " " << p.cst << endl;
			if (p.nd == y) {
				res = p.cst;
				break;
			}
			if (p.cst > dis[p.nd]) continue;
			if (vis[p.nd]) continue;
			vis[p.nd] = true;
			for (auto z:InLine[p.nd]) {
				if (z.first == p.lnn) {
					if (p.nd != at[z.first][k[z.first]].a) {
						dis[at[z.first][z.second + 1].a] = min(dis[at[z.first][z.second + 1].a], p.cst);
						pq.push({p.cst, at[z.first][z.second + 1].a, p.lnn});
					}
					if (p.nd != at[z.first][1].a) {
						dis[at[z.first][z.second - 1].a] = min(dis[at[z.first][z.second - 1].a], p.cst);
						pq.push({p.cst, at[z.first][z.second - 1].a, p.lnn});
					}
				} else {
					if (p.nd != at[z.first][k[z.first]].a) {
						dis[at[z.first][z.second + 1].a] = min(dis[at[z.first][z.second + 1].a], p.cst + 2 * at[z.first][z.second - 1].t);
						pq.push({p.cst + 2 * at[z.first][z.second + 1].t, at[z.first][z.second + 1].a, z.first});
					}
					if (p.nd != at[z.first][1].a) {
						dis[at[z.first][z.second - 1].a] = min(dis[at[z.first][z.second - 1].a], p.cst + 2 * at[z.first][z.second - 1].t);
						pq.push({p.cst + 2 * at[z.first][z.second - 1].t, at[z.first][z.second - 1].a, z.first});
					}
				}
			}
		}
		cout << res + w[x] + w[y] << endl;
	}
}
void c22_23() {
	
}
void Standard() {
	
}
void n2() {
	
}
int main() {
	#ifndef LOCALENV
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	w.resize(m + 1);
	k.resize(n + 1);
	at.resize(n + 1);
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		ks += k[i];
		at[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++)
			cin >> at[i][j].a >> at[i][j].t;
	}
	if (1 <= c && c <= 11) {
		brute();
	} else if (12 <= c && c <= 19) {
		specialB();
	} else if (c == 22 || c == 23) {
		c22_23();
	} else if (c == 20 || c == 21) {
		n2();
	}
	else {
		Standard();
	}
	return 0;
}
