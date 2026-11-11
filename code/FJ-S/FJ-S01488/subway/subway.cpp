#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 2;

int c, n, m, d, q, tot, w[N], k[N], dis[N], dis2[N];
vector <int> mp[N];
int T[N][22];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	vector <vector <int> > e(n + 2), t(n + 2);
	for (int i = 1;i <= n;i++) {
		cin >> k[i];
		e[i].reserve(k[i] + 2);
		t[i].reserve(k[i] + 2);
		for (int j = 1;j <= k[i];j++)
			cin >> e[i][j] >> t[i][j], mp[e[i][j]].push_back(i), T[e[i][j]][i] = t[i][j];
	}
	
	while (q--) {
		if (12 <= c && c <= 19) {
			priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > P, Q;
			int x, y;
			cin >> x >> y;
			Q.push({x, 0});
			P.push({y, 0});
			for (int j = 1;j <= m;j++) dis[j] = 2e18, dis2[j] = 2e18;
//			dis[x] = dis2[y] = 0;
			int ans = 0;
			while (1) {
				pair <int, int> h = Q.top();
				Q.pop();
				if (dis2[h.first] < 2e18) {
					ans = dis[h.first] + dis2[h.first];
					break;
				}
				if (h.second < dis[h.first]) dis[h.first] = h.second;
				else goto nxt;
				for (int i = 0;i < (int)mp[h.first].size();i++) {
					for (int j = 1;j <= k[mp[h.first][i]];j++) {
						int nxt = e[mp[h.first][i]][j];
						if (dis[h.first] + 2 * T[h.first][mp[h.first][i]] < dis[nxt])
							Q.push({nxt, dis[h.first] + 2 * T[h.first][mp[h.first][i]]});
					}
				}
				nxt:;
				
				h = P.top();
				P.pop();
				if (dis[h.first] < 2e18) {
					ans = dis[h.first] + dis2[h.first];
					break;
				}
				if (h.second < dis2[h.first]) dis2[h.first] = h.second;
				else continue;
				for (int i = 0;i < (int)mp[h.first].size();i++) {
					for (int j = 1;j <= k[mp[h.first][i]];j++) {
						int nxt = e[mp[h.first][i]][j];
						if (dis2[h.first] + 2 * T[h.first][mp[h.first][i]] < dis[nxt])
							P.push({nxt, dis2[h.first] + 2 * T[h.first][mp[h.first][i]]});
					}
				}
			}
			cout << w[x] + w[y] + ans << endl;
			continue;
		}
		priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > Q;
		int x, y;
		cin >> x >> y;
		Q.push({x, 0});
		for (int j = 1;j <= m;j++) dis[j] = 2e18;
//		dis[x] = 0;
		while (Q.size()) {
			pair <int, int> h = Q.top();
			Q.pop();
			if (h.second < dis[h.first]) dis[h.first] = h.second;
			else continue;
			for (int i = 0;i < (int)mp[h.first].size();i++) {
				for (int j = 1;j <= k[mp[h.first][i]];j++) {
					int nxt = e[mp[h.first][i]][j];
					if (dis[h.first] + T[h.first][mp[h.first][i]] + t[mp[h.first][i]][j] < dis[nxt])
						Q.push({nxt, dis[h.first] + T[h.first][mp[h.first][i]] + t[mp[h.first][i]][j]});
				}
			}
		}
//		cout << w[x] << " " << w[y] << " " << dis[y] << endl;
		cout << w[x] + w[y] + dis[y] << endl;
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
