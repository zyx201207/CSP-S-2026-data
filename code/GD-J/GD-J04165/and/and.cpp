#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[200005],b[200005];
void dfs(long long step,long long s)
{
	if(step>m)
	{
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(step==1)dfs(step+1,a[i]);
			else dfs(step+1,s&a[i]);
			b[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(m==1)
	{
		printf("%lld",a[n]);
		return 0;
	}
	else if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		printf("%lld",ans);
		return 0;
	}
	else if(n<=20)
	{
		dfs(1,0);
		printf("%lld",ans);
		return 0;
	}
	else
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
		printf("%lld",ans);
		return 0;
	}
	return 0;
} 
