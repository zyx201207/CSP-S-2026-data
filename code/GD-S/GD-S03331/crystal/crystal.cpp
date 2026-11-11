#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,s[500005],z[500005],mx,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		z[i]=i*a[i]-s[i];
		if(z[i]<=m)
		{
			mx=max(mx,i);
		}
	}
	long long cnt=mx+1;
	for(long long i=cnt;i<=n;i++)
	{
		for(long long j=1;j<=i;j++)
		{
			if(i-j<=mx)
			{
				break;
			}
			sum=s[i]-s[j];
			z[i]=(i-j)*a[i]-sum;
			if(z[i]<=m)
			{
				mx=max(mx,i-j);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
}
