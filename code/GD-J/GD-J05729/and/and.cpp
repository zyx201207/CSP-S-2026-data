#include <bits/stdc++.h>
using namespace std;
long long a[200005];

long long andand(long long x,long long y)
{
	long long sum;
	if(y==1)
	{
		sum = a[2];
	}
	else
	{
		sum = a[1];
	}
	for(int i = 1;i<=x;i++)
	{
		if(i!=y);
		{
			sum = (sum&i);
		}
	}
	return sum;
}

int main()
{
	freopen("and.in",'w',stdin());
	freopen("and.out",'r',stdout());
	
	long long n,m,ans=0;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		for(int i = 1;i<=n;i++)
		{
			ans = max(ans,a[i]);
		}
	}
	else if(m==2)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				ans = max(ans,a[i] & a[j]);
			}
		}
	}
	else if(m == n-1)
	{
		for(int i = 1;i<=n;i++)
		{
			ans = max(ans,andand(n,i));
		}
	}
	else if(m==n)
	{
		ans = andand(n,-1);
	}
	else
	{
		long long minn=1e10;
		for(int i = 1;i<=n;i++)
		{
			minn = min(minn,a[i]);
		}
		ans = minn;
	}
	
	cout << ans << endl;
	return 0;
}
