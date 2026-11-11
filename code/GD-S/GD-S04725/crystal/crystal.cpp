#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
long long d[500005];
long long n,m;
long long ans;
bool cmp(long long b,long long c)
{
	return b>c;
}
bool check(long long num)
{
	long long minn=1e18;
	for(int i=1;i<=(n-num+1);i++)
	{
		long long maxn=0;
		for(int j=i+1;j<=(num+i-1);j++)
		{
			maxn+=d[j]-d[i];
		 }
		 minn=min(minn,maxn);
	}
	if(num==5000)
	{
		cout<<minn<<" ";
	}
	return minn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fg=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
	{
		d[i]=a[1]-a[i];
	}
	long long s=a[1]-a[2];
	for(int i=2;i<=n;i++)
	{
		if((a[i]-a[i+1])!=s)
		{
			fg=1;
		}
	}
	if(fg==0)
	{
		ans=1;
		for(int i=2;i<=n;i++)
		{
			if(m-d[i]>=0)
			{
				ans++;
				m-=d[i];
			}
			else
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	long long l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
