#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001];
long long n,m;
long long hs(long long x)
{
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-x;
		if(b[i]<0)
		{
			b[i]=m+1;
		}
	}
	sort(b+1,b+n+1);
	long long ss=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		ss+=b[i];
		cnt++;
		if(ss>m)
		{
			cnt--;
			ss-=b[i];
			break;
		}
	}
	return cnt;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n>10000)
	{
		int aa=a[n/2],bb=a[n/2+1],cc=a[n/2-1];
		printf("%lld",max(max(hs(aa),hs(bb)),hs(cc)));
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,hs(a[i]));
		}
		printf("%lld",ans);
	}
	return 0;
}
