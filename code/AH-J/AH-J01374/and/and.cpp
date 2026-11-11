#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,k,n,m,sum,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	if(m==3)
	{
		for(i=1;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<=n;k++)
					ans=max(ans,a[i]&a[j]&a[k]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		for(i=1;i<=n;i++)
		{
			sum=1;
			for(j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=1;
		for(i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	ans=a[n]&a[n-1];
	cout<<ans;
	return 0;
}
