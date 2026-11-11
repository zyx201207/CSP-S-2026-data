#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500010],sum,vis[200010],ans1;
void dfs(long long cnt,long long ans,long long vis[])
{
	if(cnt==m)
	{
		ans1=max(ans1,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)	continue;
		vis[i]=1;
		dfs(cnt+1,(ans&a[i]),vis);
		vis[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(m==1)	printf("%lld\n",a[n]);
	else if(m==n)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		printf("%lld\n",sum);
	}
	else if(m==2)
	{
		printf("%lld\n",(a[n]&a[n-1]));
	}
	else if(m==n-1)
	{
		sum=a[2];
		for(int i=3;i<=n;i++)
		{
			sum=(sum&a[i]);
		}
		printf("%lld\n",sum);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(1,a[i],vis);
			vis[i]=0;
		}
		printf("%lld\n",ans1);
	}
	return 0;
}
