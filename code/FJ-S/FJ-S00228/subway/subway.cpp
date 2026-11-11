#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int NM = 505, MM = 20005;
int c, n, m, d, q;
bool ved[MM];
int vs[MM], ts[MM][NM], dp[MM][MM];
//站台对应线路 
vector<int> ls[NM], g[NM];

void dfs(int i, int ll) {
	if (ved[i]) return;
	ved[i] = 1;
	auto s = ls[i].size();
	if (s <= 1) continue;
	for (int k = 0; k < s - 1; k ++) {
		for (int j = i + 1; j < s; j ++) {
			int l1 = ls[i][k], l2 = ls[i][j];
			if (dp[ls[i]][l2]) dp[l1][l2] = min(dp[l1][l2], ts[l1][i] + ts[l2][i]);
			else dp[l1][l2] = ts[l1][i] + ts[l2][i];
			dp[l1][l2] = min(dp[l1][l2], dp[ll][l1] + ts[i][l1] + ts[i][l2]);
			dfs(i, l1);
		}
	}
	ved[i] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> vs[i];
	for (int i = 1; i <= n; i ++) {
		int k, a;
		cin >> k;
		while (k --) {
			cin >> a;
			cin >> ts[i][a];
			ls[a].push_back(i);
//			if (ts[i][0]) ts[i][0] = min(ts[i][0], ts[i][a]);
//			else ts[i][0] = ts[i][a];
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		dfs(i, 0);
	}
	
//	while (q --)
}
 
