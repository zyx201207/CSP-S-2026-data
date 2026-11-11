#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 20;
int c, t, n, d, ans, flag, a[N], s[N], dis[301][301][301];
void dfs(int l, int r, int id, int cnt)
{
	if(id == r)
	{
		dis[l][r][cnt]++;
		return ;
	}
	for(int i = id + 1; i <= r; i++)
	{
		if(a[i] - a[id] <= d)
		{
			if(a[r] - a[i] <= d)
			{
				dfs(l, r, i, cnt + 1);
			}
		}
		else{
			return ;
		}
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if(c == 11 || c == 12)
		{
			int p = d / (a[2] - a[1]);
			if(p == 1 || p == 0 || 2 * p > n)
			{
				cout << 0 << "\n";
			}
			else{
				cout << n - 2 * p + 1 << "\n";
			}
		}
		else
		{
			ans = 0;
			for(int i = 1; i <= n; i++)
			{
				for(int j = i + 3; j <= n; j++)
				{
					dfs(i, j, i, 0);
					for(int k = j - i; k >= 1; k--)
					{
						if(dis[i][j][k])
						{
							if(dis[i][j][k] == 2)
							{
								ans++;
							}
						}
						dis[i][j][k] = 0;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
