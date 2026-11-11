#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 507, M = 5e5 + 7, INF = 2e17;
int c, n, m, d, Q, w[M], dp[N][N];
vector<pair<int, int>> s[M];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		while(k--){
			int a, t; cin >> a >> t;
			s[a].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = i == j ? 0 : INF;
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < s[i].size(); j++){
			for(int k = j + 1; k < s[i].size(); k++){
				pair<int, int> p = s[i][j], q = s[i][k];
				dp[p.first][q.first] = min(dp[p.first][q.first], p.second + q.second);
				dp[q.first][p.first] = min(dp[q.first][p.first], p.second + q.second);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while(Q--){
		int x, y, ans = INF; cin >> x >> y;
		for(pair<int, int> i : s[x]){
			for(pair<int, int> j : s[y]){
				ans = min(ans, dp[i.first][j.first] + i.second + j.second);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
