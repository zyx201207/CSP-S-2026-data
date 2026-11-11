#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
long long way,ans,minstep;
void dfs(long long l,long long r,long long time)
{
	if (time == minstep)
	{
		return;
	}
	for (long long i = 1;i <= n;i++)
	{
		if (a[l + i] - a[l] <= d)
		{
			if (l + i == r)
			{
				way++;
				return;
			}

			dfs(l + i,r,time + 1);

		}
		else
		{
			return;
		}
	}
}
void min_dfs(long long l,long long r)
{
	if (a[l + 1] - a[l] > d)
	{
		minstep = -1;
		return;
	}
	for (long long i = 1;i <= n;i++)
	{
		if (a[l + i] - a[l] > d)
		{
			minstep++;
			min_dfs(l + i - 1,r);
			return;
		}
		if (l + i == r)
		{
			minstep++;
			return;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (long long k = 1;k <= t;k++)
	{
		cin >> n >> d;
		ans = 0;
		for (long long i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (long long i = 1;i <= n;i++)
		{
			for (long long j = i + 1;j <= n;j++)
			{
				way = 0;
				minstep = 0;
				min_dfs(i,j);
				if (minstep == -1)
				{
					continue;
				 } 
				dfs(i,j,0);
				if (way == 2)
				{
					ans++;
				 } 
			}
		}
		cout << ans << endl;
	}
	return 0;
}
