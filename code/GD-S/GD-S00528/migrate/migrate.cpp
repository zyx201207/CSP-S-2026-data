#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d;
long long a[(long long)2e6 + 5];
vector <long long> v[(long long)2e6 + 5];
long long f[(long long)2e6 + 5];
long long cnt = 0;
long long tars = 0;

long long dfs(long long x,long long tar,long long step)
{
//	printf("%d %d %d\n",x,tar,step);
	if (x == tar)
	{
		if (tars == 0)
		{
			tars = step;
			cnt = 1;
		}
		else if (tars > step)
		{
			tars = step;
			cnt = 1;
		}
		else
		{
			if (tars == step)
			{
				cnt++;
			}
		}
		return 0;
	}
	for(long long i = 0;i < v[x].size();i++)
	{
		if (f[v[x][i]])
		{
			continue;
		}
		f[v[x][i]] = 1;
		dfs(v[x][i],tar,step + 1);
		f[v[x][i]] = 0;
	}
	return 0;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		memset(v,0,sizeof v);
		cin >> n >> d;
		for(long long i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if (c == 11 || c == 12)
		{
			if (a[2] - a[1] > d)
			{
				cout << 0;
				continue;
			}
		}
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = i + 1;j <= n;j++)
			{
//				printf("%d %d %d %d \n",i,j,a[i],a[j]);
				if (abs(a[j] - a[i]) <= d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			} 
		}
		long long ans = 0;
		for(long long i = 1;i <= n;i++)
		{
			for(long long j = i + 1;j <= n;j++)
			{
				memset(f,0,sizeof f);
				cnt = 0;
				tars = 0;
				dfs(i,j,0);
				if (cnt == 2)
				{
//					printf("%d %d\n",i,j);
					ans++; 
				}
//				cout << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
