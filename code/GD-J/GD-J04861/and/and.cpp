#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int M = (1 << 30) - 1;
int n, m, ans, a[N];
void dfs(int dep, int res, int chs)
{
	if (chs == m)
	{
		ans = max(ans, res);
		return ;
	}
	if (dep > n) return ;
	dfs(dep + 1, res & a[dep], chs + 1);
	dfs(dep + 1, res, chs);
	return ;
}
bool judge()
{
	for (int i = 1; i <= n; ++i)
	{
		int cnt = 0;
		bool flg = false;
		while (cnt <= 30)
		{
			if ((1 << cnt) - 1 == a[i])
			{
				flg = true;
				break;
			}
			++cnt;
		}
		if (!flg) return false;
	}
	return true;
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n <= 20)
	{
		dfs(1, M, 0);
		ans = 0;
		cout << ans << endl;
	}
	else
	{
		if (m == 1)
		{
			for (int i = 1; i <= n; ++i) ans = max(ans, a[i]);
			cout << ans << endl;
		}
		else if (m == 2)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					if (i != j) ans = max(ans, a[i] & a[j]);
				}
			}
			cout << ans << endl;
		}
		else if (n <= 2000) 
		{
			int res = M;
			for (int i = 1; i <= n; ++i) res &= a[i];
			if (m == n) cout << res << endl;
		}
		else
		{
			int maxn = 0;
			for (int i = 1; i <= n; ++i) maxn = max(maxn, a[i]);
			if (maxn < 4)
			{
				int cnt1 = 0, cnt2 = 0, cnt3 = 0;
				for (int i = 1; i <= n; ++i)
				{
					cnt1 += (a[i] == 1);
					cnt2 += (a[i] == 2);
					cnt3 += (a[i] == 3);
				}
				if (cnt3 >= m) cout << 3 << endl;
				else if (cnt2 + cnt3 >= m) cout << 2 << endl;
				else if (cnt1 + cnt3 >= m) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else if (judge())
			{
				stable_sort(a + 1, a + n + 1);
				cout << a[n - m + 1] << endl;
			}
		}
	}
	return 0;
}
