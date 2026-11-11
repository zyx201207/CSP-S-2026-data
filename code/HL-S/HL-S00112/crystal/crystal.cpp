#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];
long long hs()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
			return false;
	}
	return true;
}
long long hs2()
{
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			return false;
	}
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(hs())
	{
		for(int i=1;i<=n-1;i++)
		{
			if((1+i)*i/2>m)
			{
				cout<<i;
				return 0;
			}
			else if((1+i)*i/2==m)
			{
				cout<<i+1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else if(hs2())
	{
		int ans=1;
		long long cha=a[2]-a[1],sum=0;
		for(int i=2;i<=n;i++)
		{
			sum+=(i-1)*cha;
			if(sum<=m)ans=i;
		}
		cout<<ans;
		return 0;
	}
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		for(int j=i+1;j<=n;j++)
		{
			sum+=c[j]-c[j-1];
			if(sum<=m)
			{
				ans=max(ans,j-i+1);
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
