#include <bits/stdc++.h>

using namespace std;

struct node {
	int i, w;
};

const int N = 5e5 + 10;
int w[N];
vector<node> t[N];

int ret = 0;
void dfs(int now, int route) {
//	for (int i = 1; )
}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int u, w;
			cin >> u >> w;
			t[u].push_back({i, w});
//			dp[a[i][j]].push_back({a[i][j], t[i][j]});
//			for (int l = 1; l < j; l++) {
//				dp[a[i][j]].push_back({a[i][l], t[i][j] + t[i][l]});
//				dp[a[i][l]].push_back({a[i][j], t[i][j] + t[i][l]});
//			}
		} 
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int size = t[x].size();
		ret = 0;
		for (int i = 0; i < size; i++) {
			dfs(x, t[x].i);
		}
	}
	return 0;
} 
