#include<bits/stdc++.h> 
#define int long long
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define pii pair<int, int>
using namespace std;

int c, n, m, d, q, w[500005], x, y, dp[505][505];
vector<pii> l[500005];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	f(i, 1, m) cin >> w[i];
	f(i, 1, n){
		int _;
		cin >> _;
		f(j, 1, _) cin >> x >> y, l[x].push_back({i, y});
	}
	f(i, 1, n) f(j, 1, n) if(i != j) dp[i][j] = 2e18;
	f(i, 1, m){
		int sz = l[i].size();
		f(j, 0, sz - 1) f(k, 0, sz - 1) if(j != k)
			dp[l[i][j].first][l[i][k].first] = dp[l[i][k].first][l[i][j].first] = l[i][j].second + l[i][k].second;
	}
	f(k, 1, n) f(i, 1, n) f(j, 1, n)
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	while(q--){
		cin >> x >> y;
		int ans = 2e18;
		for(auto ed : l[x])
			for(auto ed2 : l[y])
				ans = min(ans, ed.second + ed2.second + dp[ed.first][ed2.first]);
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
