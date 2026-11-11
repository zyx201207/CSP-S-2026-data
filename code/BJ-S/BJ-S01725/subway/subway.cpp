#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500005];
int k[505];
int dis[505][505];
vector<int> a[505];
vector<int> t[505];
vector<pair<int, int>> h[500005]; // h[i]表示有哪些线路经过了节点i, 到站台的距离是多少
inline void initIO() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
}
void Read() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			int u, v;
			cin >> u >> v;
			a[i].push_back(u);
			t[i].push_back(v);
			h[u].push_back({i, v});
		}
	}
}
void Init() {
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i ++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i ++)
		for (int s = 0; s < h[i].size(); s ++)
			for (int e = 0; e < h[i].size(); e ++)
				dis[h[i][s].first][h[i][e].first] = min(dis[h[i][s].first][h[i][e].first], h[i][s].second + h[i][e].second);
}
void Core() {
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
void Write() {
	while (q --) {
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		for (const auto& i : h[x])
			for (const auto& j : h[y])
				ans = min(ans, dis[i.first][j.first] + i.second + j.second);
		cout << w[x] + w[y] + ans << endl;
	}
}
void Test() {
	cout << "h-------------------------------\n";
	for (int i = 1; i <= m; i ++) {
		for (const auto& v : h[i])
			cout << "{" << v.first << ", " << v.second << "}, ";
		cout << endl;
	}
	cout << "dis-----------------------------\n";
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			cout << dis[i][j] << " ";
		cout << endl;
	}
}
signed main() {
	initIO();
	Read();
	Init();
	Core();
	Write();
	// Test();
	return 0;
}