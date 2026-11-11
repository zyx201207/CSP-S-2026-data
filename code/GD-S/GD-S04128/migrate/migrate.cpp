#include<bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e6 + 5;
int c, t, n, tot, ans;
long long d, a[maxn], r[maxn];
void dfs(int cur, int ed, int stp, int tar)
{
	if (cur == ed)
	{
		if (stp == tar)
		{
			++ tot;
		}
		return;
	}
	for (int i = cur + 1; i <= r[cur]; ++ i)
	{
		if (i > ed)
		{
			break;
		}
		dfs(i, ed, stp + 1, tar);
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		for (int i = 0; i <= n; ++ i)
		{
			r[i] = 0;
		}
		ans = 0;
		tot = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++ i)
		{
			cin >> a[i];
		}
		if (0 <= c && c <= 25)
		{
			for (int i = 1; i <= n; ++ i)
			{
				for (int j = i + 1; j <= n; ++ j)
				{
					if (a[j] - a[i] > d)
					{
						r[i] = j - 1;
						break;
					}
				}
				if (r[i] == 0)
				{
					r[i] = n;
				}
			}
			for (int i = 1; i <= n; ++ i)
			{
				//cout << "i" << i << '\n';
				for (int j = i + 1; j <= n; ++ j)
				{
					//cout << "j" << j << '\n';
					int cur = i, cnt = 0;
					bool f = true;
					while (cur < j)
					{
						if (r[cur] == cur && cur < j)
						{
							f = false;
							break;
						}
						if (r[cur] <= j)
						{
							++ cnt;
							cur = r[cur];
						}
						else
						{
							++ cnt;
							break;
						}
					}
					if (f == false)
					{
						continue;
					}
					tot = 0;
					dfs(i, j, 0, cnt);
					if (tot == 2)
					{
						//cout << i << " " << j << '\n';
						++ ans;
					}
				}
			}
			cout << ans << '\n';
			continue;
		}
	}
	return 0;
}

