#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int x[maxn], ret = 0, minn = maxn, n, d;
void dfs(int qi, int xi, int jie, int tot)
{
	if (xi == jie)
	{
		if (tot < minn)
		{
			minn = tot;
			ret = 0;
		}
		if (tot == minn)
		{
			ret++;
		}
		return;
	}
	for (int i = xi + 1; i <= jie; i++)
	{
		if (x[i] - x[xi] <= d)
		{
			dfs(qi, i, jie, tot + 1);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		bool flag = true;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
			if (i >= 3 && x[i] - x[i - 1] != x[i - 1] - x[i - 2])
			{
				flag = false;
			}
		}
		if (flag)
		{
			int ch = d / (x[2] - x[1]);
			ch *= 2;
			ch--;
			if (ch == 1)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << max(n - (ch + 1) + 1, 0) << endl;
			}
		}
		else if (n <= 9)
		{
			int ans = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					minn = maxn;
					ret = 0;
					dfs(i, i, j, 0);
					if (ret == 2)
					{
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
