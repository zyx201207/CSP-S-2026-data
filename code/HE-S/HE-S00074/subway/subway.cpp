#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 66, NN = 5e2 + 66;
vector<ll> t[NN];
vector<int> in[N];
ll c, n, m, d, q, w[N], dp[NN][NN];
unordered_map<ll, int> mp;
ll id(ll x, ll y){return (x - 1) * m + y;}
signed main()
{
	freopen("subway.in", "r", stdin);freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	memset(dp, 0x3f, sizeof(dp));
	cin >> c >> m >> n >> d >> q;
	for(int i = 1;i <= n;i ++) cin >> w[i];
	for(int i = 1;i <= m;i ++)
	{
		dp[i][i] = 0;
		int gs;cin >> gs;t[i].resize(gs + 5);
		for(int j = 1, x, v;j <= gs;j ++)
		{
			cin >> x >> v;
			t[i][j] = v;mp[id(i, x)] = j;
			in[x].push_back(i);
		}
	}
	for(int i = 1;i <= n;i ++)
		for(int j = 0, p = in[i][j];j < in[i].size();j ++, p = in[i][j])
			for(int k = j + 1, q = in[i][k];k < in[i].size();k ++, q = in[i][k])
				dp[p][q] = min(dp[p][q], t[p][mp[id(p, i)]] + t[q][mp[id(q, i)]]), dp[q][p] = dp[p][q]; 
	for(int k = 1;k <= m;k ++)
		for(int i = 1;i <= m;i ++)
			for(int j = 1;j <= m;j ++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	while(q --)
	{
		ll ans = LLONG_MAX;
		int x, y;cin >> x >> y;
		for(auto p : in[x])
			for(auto q : in[y])
				ans = min(ans, dp[p][q] + t[p][mp[id(p, x)]] + t[q][mp[id(q, y)]]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
