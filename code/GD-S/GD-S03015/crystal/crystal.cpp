#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500003];
long long s[500003];
bool cmp(long long a,long long b)
{
	return a<b;
}
long long d[500003];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=d[i]+s[i-1];
	}
	d[1]=0;
	long long l=1,r=1;
	long long sum=0;
	long long countmax=-1;
	while(r<=n)
	{
		if(l>r)
		{
			r++;
			continue;
		}
		if(sum<=m)
		{
			countmax=max(countmax,(r-l+1));
			r++;
			sum+=d[r]*(r-l); 
		}
		else
		{
			sum-=(s[r]-s[l+1]);
			l++;
		}
	}
	printf("%lld",countmax);
	return 0;
}
