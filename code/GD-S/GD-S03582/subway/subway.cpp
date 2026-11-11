#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,a1,t1,ans = 1e18,dis[503][503];
int w[500003];
vector <long long> a[500002];
vector <long long> t[500002];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		long long k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a1 >> t1;
			a[a1].push_back(i);
			t[a1].push_back(t1);
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j < a[i].size();j++)
		{
			for(int k1 = j + 1;k1 < a[i].size();k1++)
			{
				dis[a[i][j]][a[i][k1]] = min(dis[a[i][j]][a[i][k1]],t[i][j] + t[i][k1]);
				dis[a[i][k1]][a[i][j]] = dis[a[i][j]][a[i][k1]];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			for(int k1 = 1;k1 <= n;k1++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k1] + dis[k1][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++)
	{
		ans = 1e18;
		cin >> x >> y;
		for(int j = 0;j < a[x].size();j++)
		{
			for(int k1 = 0;k1 < a[y].size();k1++)
			{
				ans = min(ans,w[x] + w[y] + t[x][j] + t[y][k1] + dis[a[x][j]][a[y][k1]]); 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
