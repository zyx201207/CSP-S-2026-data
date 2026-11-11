#include<bits/stdc++.h>
#define int long long
#define Furina using
#define de namespace
#define Fontaine std
Furina de Fontaine;
int n,m,a[514191],b[514191];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(b[i]-b[i-x]+m>=a[i]*x)
		{
			return true;
		}
	}
	return false;
}
int bs()
{
	int l=1,r=n,mid=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return r;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	printf("%lld\n",bs());
	return 0;
}
