#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[5000005],b[5000005];
int find(long long ans)
{
	int l=1,r=n,mid,i;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]>ans)
		{
			r=mid-1;
		}
		else
		{
			i=mid;
			l=mid+1;
		}
	}
	return i;
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
	sort(a+1,a+n+1);
	int f1=0,f2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			f1=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i])
		{
			f2=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	if(a[n]*n-b[n]<=m)
	{
		cout<<n;
		return 0;
	}
	if(f1==0)
	{
		int ans=0;
		while(m>=0)
		{
			ans++;
			m-=ans;
		}
		cout<<ans;
		return 0;
	}
	if(f2==0)
	{
		int ans=0;
		while(m>=0)
		{
			ans+=(a[2]-a[1]);
			m-=ans;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]*i-b[i]>m)
			{
				cout<<i-1;
				break;
			}
		}
	}
}
