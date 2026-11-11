#include<bits/stdc++.h> 
using namespace std;
long long a[1000086];
long long b[1000086];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,mx=-1e20;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(a[i]>mx)
		{
			mx=a[i];
		}
	}
	sort(a+1,a+n+1);
	long long c=1,md=-1;
	for(long long i=n;i>1;i--)
	{
		if(a[i]==a[i-1])
		{
			c++;
		}
		else if(a[i]!=a[i-1]||i==2)
		{
			md=max(md,c);
			c=1;
		}
	}
	c=1;
	for(long long i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			c++;
		}
		else if(a[i]!=a[i-1]||i==n)
		{
			md=max(md,c);
			c=1;
		}
	}
	if(m==0)
	{
		cout<<md;
		return 0;
	}
	if(mx*n-sum<=m)
	{
		cout<<n;
		return 0;
	}
	long long cnt=1;
	for(long long i=1;i<n;i++)
	{
		if((a[i+1]-a[i])*i<=m)
		{
			m=m-(a[i+1]-a[i])*i;
			cnt++;
		}
		else
		{
			break;
		}
	}
	md=max(cnt,md);
	cnt=1;
	for(long long i=n;i>1;i--)
	{
		if((a[i]-a[i-1])*i<=m)
		{
			m=m-(a[i]-a[i-1])*i;
			cnt++;
		}
		else
		{
			break;
		}
	}
	cout<<max(cnt,md);
	return 0;
}
