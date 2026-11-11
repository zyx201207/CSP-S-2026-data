#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int cid,n,D,a[N],dp[N],g[N];
int lst[N],pre[N],b[N];
int read()
{
	char x=getchar();
	int sum=0,fs=1;
	while(x<'0'||x>'9')
	{
		if(x=='-') fs=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9') sum=sum*10+x-'0',x=getchar();
	return sum*fs;
}
void solve1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) dp[j]=0,g[j]=1;
		for(int j=i+1;j<=n;j++) dp[j]=1e16,g[j]=0;
		for(int j=i+1;j<=n;j++)
		{
			dp[j]=dp[lst[j]]+1;
			g[j]=g[lst[j]];
			if(lst[j]<=i) continue;
			if(lst[j]<j-1&&dp[lst[j]+1]+1==dp[j]) g[j]=min(g[j]+g[lst[j]+1],3ll);
			if(lst[j]<j-2&&dp[lst[j]+2]+1==dp[j]) g[j]=min(g[j]+g[lst[j]+2],3ll);
			ans+=(g[j]==2);
		}
//		for(int i=1;i<=n;i++) printf("%lld ",g[i]);
//		printf("\n");
		//printf("%lld : %lld\n",i,ans);
	}
	printf("%lld\n",ans);
}
void solve()
{
	n=read(),D=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1)
	{
		printf("0\n");
		return;
	}
	int j=1;
	for(int i=0;i<=n+1;i++) lst[i]=pre[i]=0;
	a[0]=a[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		while(j<=i&&a[i]-a[j]>D) j++;
		lst[i]=j;
	}
	j=1;
	for(int i=1;i<=n;i++)
	{
		while(j<=n&&a[j]-a[i]<=D) j++;
		pre[i]=j-1;
	}
	if(cid==11||cid==12)
	{
		int s=D/(a[2]-a[1]);
		if(s<=1)
		{
			printf("0\n");
			return;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i+2ll*s-1<=n) ans++;
		}
		printf("%lld\n",ans);
		return;
	}
	if(cid==13||cid==14)
	{
		int ans=0;
		for(int i=0;i<=n+1;i++) b[i]=0;
		for(int i=1;i<=n;i++)
		{
			ans+=b[lst[j]];
			b[pre[i]+1]++;
		}
		printf("%lld\n",ans);
		return;
	}
	solve1();
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%lld%lld",&cid,&T);
	while(T--) solve();
	return 0;
}
/*
记录dis[i][j]表示从点i到点j的最小距离 
*/
