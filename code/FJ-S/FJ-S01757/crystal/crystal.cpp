#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[500001],n,m,zd=0,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n>50000)
	{for(int i=n-1;i>=1;i--)
	if(m>=a[n]-a[i])
		{m-=a[n]-a[i];
	    zd++;
		}
		else
		i=0;
		cout<<zd;
	}
	
	
	
	
	
	for(int i=1;i<=n;i++)
	{
	for(int l=i;l<n;l++)
	{if(a[l]>a[l+1])
	{p=a[l];
	a[l]=a[l+1];
	a[l+1]=p;
	}
	}
	}
	for(int i=2;i<=n;i++)
	{int f=m;
		int ans=1;
		for(int l=i-1;l>=1;l--)
		if(a[i]-a[l]<=f)
		{f-=(a[i]-a[l]);
		ans++;
		}
		else
		{
		l=0;}
		if(ans>zd)
		zd=ans;
	}
	cout<<zd;
}