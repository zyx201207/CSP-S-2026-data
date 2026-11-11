# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans = 1, sum, res;
int p = 1;
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i ++)
	{
		res ++;
		sum += (a[i] - a[i - 1]) * res;
		while (sum > m)
		{
			res --;
			sum -= (a[i] - a[p]);
			p ++;
			if (p > n) break;
		} 
		if (p > n) break;
		ans = max(ans, res + 1);
	}
	cout << ans;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while (T --) solve();
	return 0;
}

