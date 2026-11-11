#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, T, n, d, x[5005], l[5005], r[5005], dis[5005][505], sum[5005][5005], ans;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for(int i = 1; i <= n; i++)
		{
			l[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
			r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				if(i != j)
				{
					dis[i][j] = 5e18;
					sum[i][j] = 0;
				}
				else sum[i][j] = 1;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(j <= r[i])
				{
					dis[i][j] = 1;
					sum[i][j] = 1;
				}
				else dis[i][j] = dis[i][l[j]] + 1;
			}
		}
		for(int k = 3; k <= n; k++)
		{
			for(int i = 1; i <= n - k + 1; i++)
			{
				for(int j = i + 1; j < i + k - 1; j++)
				{
					if(dis[i][j] + dis[j][i + k - 1] == dis[i][i + k - 1])
					{
						sum[i][i + k - 1] = min(3ll, sum[i][i + k - 1] + sum[i][j] * sum[j][i + k - 1]);
					}
				}
			}
		}
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(sum[i][j] == 2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

