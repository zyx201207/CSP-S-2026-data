#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
using namespace std;
int n,m;
bool flag,x;
ll a[maxn],ans,p,b[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	x=1; flag=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		if(a[i]>=4) flag=0;
	}
	p=a[1];
	for(int i=2;i<=n;++i)
		if(a[i]!=p)
		{
			x=0;
			break;
		}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;++i) ans&=a[i];
		printf("%lld",ans);
		return 0;
	}
	if(m==n-1)
	{
		ans=a[1];
		for(int i=2;i<=n;++i)
			for(int j=2;j<=n;++j) if(j!=i) ans&=a[j];
		ll ans2=a[2];
		for(int i=3;i<=n;++i) ans2&=a[i];
		printf("%lld",ans2);
		return 0; 
	}
	if(m==1)
	{
		for(int i=1;i<=n;++i) ans=max(ans,a[i]);
		printf("%lld",ans);
		return 0;
	}
	if(m==2)
	{	
		ll c;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
			{	
				c=i&j;
				ans=max(ans,c);
			}
		printf("%lld",ans);
		return 0;
	}
	if(flag)
	{
		if(x) printf("%lld",p);
		else printf("0");
		return 0;
	}
	if(n<=20)
	{
		ll c[maxn*2];
		for(int i=1;i<=n;++i) c[i]=a[i];
		for(int i=n+1;i<=n*2;++i) c[i]=a[i-n];
		for(int i=1;i<=n*2;++i)
		{
			b[i]=c[i];
			for(int j=i+1;j<=i+m-1;++j) b[i]&=c[j];
		}
		for(int i=1;i<=n;++i) ans=max(c[i],ans);	
		printf("%lld",ans);	
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
		return 0;
	}
	return 0;
}
