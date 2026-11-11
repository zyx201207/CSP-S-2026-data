#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
const int M = 1e3 + 5;
int c, n, m, d, T;
long long w[500005], k[N], a[M][M], b[N][N];
vector<pair<int, long long>> v[N];
vector<int> e1[500005];
set<int> e2[N];
bitset<N> vis;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> T;
	if (1 <= c && c <= 11) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				a[i][j] = 1e18;
			}
		}
		for (int i = 1; i <= m; ++i) {
			cin >> w[i];
			a[i][i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> k[i];
			v[i].resize(k[i]);
			for (int j = 0; j < k[i]; ++j) {
				cin >> v[i][j].first >> v[i][j].second;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < k[i]; ++j) {
				for (int l = j; l < k[i]; ++l) {
					a[v[i][j].first][v[i][l].first] = v[i][j].second + v[i][l].second;
					a[v[i][l].first][v[i][j].first] = v[i][j].second + v[i][l].second;
				}
			}
		}
		for (int l = 1; l <= m; ++l) {
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= m; ++j) {
					a[i][j] = min(a[i][j], a[i][l] + a[l][j]);
				}
			}
		}
		while (T--) {
			int x, y;
			cin >> x >> y;
			cout << w[x] + w[y] + a[x][y] << '\n';
		}
	}
	else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				b[i][j] = 0;
			}
		}
		for (int i = 1; i <= m; ++i) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> k[i];
			v[i].resize(k[i]);
			for (int j = 0; j < k[i]; ++j) {
				cin >> v[i][j].first >> v[i][j].second;
				e1[v[i][j].first].push_back(i);
				e2[i].insert(v[i][j].first);
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (auto j : e1[i]) {
				for (auto l : e1[i]) {
					b[j][l] = 1;
				}
			}
		}
		while (T--) {
			int x, y;
			cin >> x >> y;
			vis.reset();
			int cnt = 0;
			queue<pair<int, int>> q;
			for (int i = 1; i <= n; ++i) {
				if (e2[i].find(x) != e2[i].end()) {
					q.push({i, 1});
				}
			}
			while (true) {
				pair<int, int> _ = q.front();
				int xx = _.first;
				int yy = _.second;
				q.pop();
				if (e2[xx].find(y) != e2[xx].end()) {
					cnt = yy;
					break;
				}
				if (vis[xx]) continue;
				vis[xx] = true;
				for (int i = 1; i <= n; ++i) {
					if (!vis[i] && (b[xx][i] || b[i][xx])) {
						q.push({i, yy + 1});
					}
				}
			}
			cout << w[x] + w[y] + 2ll * cnt * v[1][0].second << '\n';
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
const int M = 5e5 + 5;
int c, n, m, d, T;
long long w[M], k[N];
bool b[N][N];
vector<pair<int, long long>> v[N];
vector<int> e1[M];
bitset<N> vis;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> T;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		v[i].resize(k[i]);
		for (int j = 0; j < k[i]; ++j) {
			cin >> v[i][j].first >> v[i][j].second;
			e1[v[i][j].first].push_back(i);
		}
		sort(v[i].begin(), v[i].end());
	}
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < e1[i].size(); ++j) {
				for (int l = j + 1; l < e1[i].size(); ++l) {
					b[e1[i][j]][e1[i][l]] = true;
				}
			}
		}
		while (T--) {
			int x, y;
			cin >> x >> y;
			vis.reset();
			priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
			for (int i = 1; i <= n; ++i) {
				if ((*lower_bound(v[i].begin(), v[i].end(), (pair<int, long long>){x, 0})).first == x) {
					q.push({i, 1});
				}
			}
			while (true) {
				pair<int, int> _ = q.top();
				int xx = _.first;
				int yy = _.second;
				q.pop();
				if (e2[xx].find(y) != e2[xx].end()) {
					cout << w[x] + w[y] + yy << '\n';
					break;
				}
				if (vis[xx]) continue;
				vis[xx] = true;
				for (int i = 1; i <= n; ++i) {
					if (!vis[i] && (b[xx][i] || b[i][xx])) {
						q.push({i, yy + 1});
					}
				}
			}
		}
	return 0;
}*/
/*
5 5
1 2 4 8 9
*/
