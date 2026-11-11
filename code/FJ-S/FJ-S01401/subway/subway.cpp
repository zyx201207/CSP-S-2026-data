#include <bits/stdc++.h>
#define int long long
using namespace std;

int C, n, m, d, Q, vcnt, w[500005], k[505];
int dis[805][805];
vector<pair<int, int> > pass[500005];

void sol1() {
	for(int i = 1;i <= m;i ++) {
		cin >> w[i];
	}
	vcnt = m;
	for(int i = 1;i <= 800;i ++) {
		for(int j = 1;j <= 800;j ++) {
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1;i <= n;i ++) {
		cin >> k[i];
		for(int j = 1, tmp;j <= k[i];j ++) {
			cin >> tmp;
			cin >> dis[tmp][++ vcnt];
			dis[vcnt][tmp] = dis[tmp][vcnt];
			if(j == 1) continue;
			dis[vcnt - 1][vcnt] = dis[vcnt][vcnt - 1] = 0;
		}
	}
//	cout << vcnt << "\n";
	for(int k = 1;k <= vcnt;k ++) {
		for(int i = 1;i <= vcnt;i ++) {
			for(int j = 1;j <= vcnt;j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q --) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dis[x][y] << "\n";
	}
}

void sol3() {
	for(int i = 1;i <= m;i ++) {
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1;i <= n;i ++) {
		cin >> k[i];
		for(int j = 1, tmp1, tmp2;j <= k[i];j ++) {
			cin >> tmp1 >> tmp2;
			pass[tmp1].push_back({i, tmp2});
		}
	}
	for(int i = 1;i <= m;i ++) {
		for(auto x : pass[i]) {
			for(auto y : pass[i]) {
				if(x == y) continue;
				dis[x.first][y.first] = min(dis[x.first][y.first], x.second + y.second);
				dis[y.first][x.first] = dis[x.first][y.first];
			}
		}
	}
	for(int k = 1;k <= n;k ++) {
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;i ++) {
		dis[i][i] = 0;
	}
	while(Q --) {
		int x, y, ans = 1e18;
		cin >> x >> y;
		for(auto p : pass[x]) {
			for(auto q : pass[y]) {
				int i = p.first, j = q.first;
				ans = min(ans, w[x] + w[y] + p.second + q.second + dis[i][j]);
			}
		}
		cout << ans << "\n";
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> C >> n >> m >> d >> Q;
	if(C <= 3) {
		sol1();
	}else {
		sol3();
	}
	return 0;
}
