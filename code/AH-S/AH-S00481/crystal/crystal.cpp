#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,mid,r,f,ans=1,d[500005],sum[500005];
bool ch(long long x)
{
	long long mi=LONG_LONG_MAX;
	for(int i=x;i<=n;i++)
	{
		long long s=0,f=0;
		for(int j=i-x+1;j<=i;j++)
		{
			s+=a[i]-a[j];
		}
		if(f==0)
		{
			mi=min(mi,s);
		}
	}
	if(mi<=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) f=1;
	}
	if(f==0)
	{
		long long t=0;
		while(1)
		{
			t++;
			if(t*(t+1)>m) break;
		}
		cout<<min(n,t+1);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[n]-a[i];
	}
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ch(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
			
		}
	}
	cout<<min(n,ans);
}
//Oct31==Dec25?
