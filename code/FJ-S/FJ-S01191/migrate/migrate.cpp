#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t --)
	{
		long long n,d;
		cin >> n >> d;
		vector<long long> x(n + 1,0);
		vector<vector<int>> dis,cnt;
		dis.resize(n + 1,vector<int>(n + 1,n + 11));
		cnt.resize(n + 1,vector<int>(n + 1,0));
		for(int i = 1;i <= n;++ i)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;++ i)
		{
			for(int j = i + 1;j <= n;++ j)
			{
				if(x[j] - x[i] <= d)
				{
					dis[i][j] = 1;
					cnt[i][j] = 1;
				}
			}
		}
		for(int i = 1;i <= n;++ i)
		{
			for(int j = 1;j + i <= n;++ j)
			{
				for(int k = j;k <= j + i;++ k)
				{
					if(dis[j][j + i] > dis[j][k] + dis[k][j + i])
					{
						dis[j][j + i] = dis[j][k] + dis[k][j + i];
					}
				}
			}
		}
		for(int i = 1;i <= n;++ i)
		{
			for(int j = 1;j + i <= n;++ j)
			{
				for(int k = j;k <= j + i;++ k)
				{
					if(dis[j][j + i] == dis[j][k] + dis[k][j + i])
					{
						cnt[j][j + i] += cnt[j][k] * cnt[k][j + i];
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;++ i)
		{
			for(int j = i + 1;j <= n;++ j)
			{
//				cout << cnt[i][j] << ' ';
				if(cnt[i][j] == 2)
				{
					++ ans;
				}
			}
//			cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
