#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500010];
int dis[550][550];
int b[550];
vector<pair<int, int> > dn[500010];
vector<int>e[550];

void dfs(int st, int l) {
	for(auto r : e[l]) {
		if(b[r]) continue;
		dis[st][r] = dis[st][l] + dis[l][r];
		b[l] = 1;
		dfs(st, r);
		b[l] = 0;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, x, y, k; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> x >> y;
			dn[x].push_back({i, y});
		}
	}
	for(int i = 1; i <= m; i++) {
		for(auto x : dn[i]) {
			for(auto y : dn[i]) {
				int px = x.first, py = y.first;
				if(px == py)continue;
				dis[px][py] = x.second + y.second;
				e[px].push_back(py);
				e[py].push_back(px);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		dfs(i, i);
	}
	while(q--) {
		int x, y, ans = 0x3f3f3f3f;
		cin >> x >> y;
		for(auto l : dn[x]) {
			for(auto r : dn[y]) {
				ans = min(ans, dis[l.first][r.first] + w[x] + w[y] + l.second + r.second);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
