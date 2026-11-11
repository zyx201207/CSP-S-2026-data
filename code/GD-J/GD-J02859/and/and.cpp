#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,vis[200010];
void dfs(long long x,long long m,bool p)
{
	if(p==0)for(int i=1;i<=n;i++)dfs(a[i],m,1);
	if(m==0)
	{
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(x&a[i],m-1,1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=20)dfs(0,m,0);
	else if(n<=2000) 
	{
		if(m==1)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		else if(m==n)
		{
			ans=a[1];
			for(int i=1;i<=n;i++)ans&=a[i];
		}
	}
	else for(int i=1;i<=n;i++)ans=min(ans,a[i]);
	printf("%lld",ans);
	return 0;
}
