#include<bits/stdc++.h>
using namespace std;
//remember to put on long long !!!
using ll = long long;
constexpr int N = 2e6+5;
ll x[N];
//int lft[N], rgt[N], dis[N], u[N], v[N];
//struct Msg {
//	int minn, cnt;
//};
int dp[N], vis[N];
// Msg -> segment tree's return type
// firstly make the easy mode, to test thought true whether.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --)
	{
		memset(dp, 0x3f, sizeof dp);
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
			cin >> x[i];
		int ans = 0;
		for (int i = 1; i < n; i ++)
		{
			dp[i] = 0;
			vis[i] = 1;
			for (int j = i + 1; j <= n; j ++)
			{
				for (int k = j - 1; x[j] - x[k] <= d && k >= i; k --)
					if (dp[j] > dp[k] + 1)
					{
						dp[j] = dp[k] + 1;
						vis[j] = vis[k];
					}
					else if (dp[j] == dp[k] + 1)
						vis[j] += vis[k];
				if (vis[j] == 2)
					++ ans;
			}
			for (int j = i + 1; j <= n; j ++)
				dp[j] = 0x3f3f3f3f, vis[j] = 0;
		}
		cout << ans << '\n';
//		int last = 1;
//		for (int i = 1; i <= n; i ++)
//		{
//			cin >> x[i];
//			while (x[i] - x[last] > d)
//				++ last;
//			lft[i] = last;
//		}
//		last = n;
//		for (int i = n; i > 0; i --)
//		{
//			while (x[last] - x[i] > d)
//				-- last;
//			rgt[i] = last;
//		}
////		delete last; hhhh
//		//hope it works
//		for (int i = 1; i <= n; i ++)
	}
	return 0;
}
