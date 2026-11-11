#include<bits/stdc++.h>
#define LL long long
using namespace std;
int ceshidian,T;
int n,b[2000005],nx[2000005],pr[2000005];
LL m,a[2000005],dp[2000005];
void init()
{
	return;
}
void solve()
{
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(ceshidian==11||ceshidian==12)
	{
		if(a[2]-a[1]>=m)
		{
			puts("0");
			return;
		}
//		printf("%lld %lld %lld\n",a[2]-a[1],m,m/(a[2]-a[1]));
		m/=(a[2]-a[1]);
		m*=2;
		m--;
		printf("%lld\n",max(0ll,(LL)n-m));
		return;
	}
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<n&&a[j+1]-a[i]<=m) j++;
		nx[i]=j;
	}
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<i&&a[i]-a[j]>m) j++;
		pr[i]=j;
	}
	int tot=0;
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		tot=nx[i];
		dp[i]=1;
		if(a[i+1]-a[i]>m) continue;
		for(int j=i;j<=nx[i];j++) dp[j]=1;
		for(int j=tot+1;j<=n;j++)
		{
			dp[j]=0;
			if(a[j]-a[j-1]>m) break;
			if(j>nx[tot])
			{
				tot=nx[tot];
			}
			int ls=pr[j];
			if(tot-ls+1<=2&&ls<=tot)
			{
				for(int k=ls;k<=tot;k++) dp[j]+=dp[k],dp[j]=min(dp[j],3ll);
				if(dp[j]==2) ans++; 
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&ceshidian,&T);
	while(T--)
	{
		init();
		solve();
	}
	return 0;
}
