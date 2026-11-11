#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],v[200010],k,mx=0,ans=0,sum;
void dfs(ll x)
{
	if(x>m)ans=max(ans,sum);
	for(ll i=1;i<=n;i++)if(!v[i])
	{
		if(x==1)
		{
			v[i]=1;sum=a[i];
			dfs(x+1);
			sum=0;v[i]=0;
		}
		else
		{
			ll o=sum;
			v[i]=1;sum&=a[i];
			dfs(x+1);
			sum=o;v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
	k=a[1];for(ll i=2;i<=n;i++)k&=a[i];
	if(n<=20)
	{
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	if(m==1)printf("%lld",mx);
	else if(m==n)printf("%lld",k);
	else if(m==2)
	{
		if(n<=2000)
		{
			for(ll i=1;i<n;i++)for(ll j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
		}
		else
		{
			sort(a+1,a+n+1);
			for(ll i=1;i<n;i++)ans=max(ans,a[i]&a[i+1]);
		}
		printf("%lld",ans);
	}
	else if(mx<4)
	{
		ll cnt=0,b=0,c=0;
		for(ll i=1;i<=n;i++)
		{
			if(a[i]==1)cnt++;
			else if(a[i]==2)b++;
			else c++;
		}
		if(c>=m)printf("3");
		else if(b+c>=m)printf("2");
		else if(cnt+c>=m)printf("1");
		else printf("0");
	}
	else if(m==n-1)
	{
		sum=a[1];
		for(ll i=2;i<n;i++)sum=sum&a[i];
		ans=a[2];
		for(ll i=3;i<=n;i++)ans=ans&a[i];
		printf("%lld",max(ans,sum));
	}
	else
	{
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
	}
	return 0;
}
