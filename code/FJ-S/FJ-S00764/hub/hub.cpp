#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=2000000;
int n,k,tot,head[N],nxt[N],to[N],ans,dp1[N],dp2[N],dp[N],c[N];
bool vis[N];
void add(int u,int v)
{
	nxt[tot]=head[u];
	to[tot]=v;
	head[u]=tot++;
}
void dfs1(int u,int f,int x)
{
	int i,v;
	vis[u]=1;
	for (i=head[u];i>=0;i=nxt[i]) if (i!=x)
	{
		v=to[i];
		if (v==f) continue;
		dp1[v]=dp1[u]+1;
		dfs1(v,u,x);
	}
}
void dfs2(int u,int f,int x)
{
	int i,v;
	dp[u]=0;
	for (i=head[u];i>=0;i=nxt[i]) if (i!=x)
	{
		v=to[i];
		if (v==f) continue;
		dfs2(v,u,x);
		dp[u]=max(dp[u],dp[v]+1);
	}
}
void work(int x)
{
	int i,u,v;
	for (i=1;i<=n;i++) vis[i]=0;
	dp1[to[x]]=0;
	dfs1(to[x],0,x^1);
	u=to[x];
	for (i=1;i<=n;i++) if (vis[i]&&dp1[u]<dp1[i]) u=i;
	dp1[u]=0;
	dfs1(u,0,x^1);
	for (i=1;i<=n;i++) dp2[i]=dp1[i];
	u=to[x];
	for (i=1;i<=n;i++) if (vis[i]&&dp1[u]<dp1[i]) u=i;
	dp1[u]=0;
	dfs1(u,0,x^1);
	u=to[x];
	for (i=1;i<=n;i++) if (vis[i]&&max(dp1[u],dp2[u])>max(dp1[i],dp2[i])) u=i;
	for (i=1;i<=n;i++) vis[i]=0;
	dp1[to[x^1]]=0;
	dfs1(to[x^1],0,x);
	v=to[x^1];
	for (i=1;i<=n;i++) if (vis[i]&&dp1[v]<dp1[i]) v=i;
	dp1[v]=0;
	dfs1(v,0,x);
	for (i=1;i<=n;i++) dp2[i]=dp1[i];
	v=to[x^1];
	for (i=1;i<=n;i++) if (vis[i]&&dp1[v]<dp1[i]) v=i;
	dp1[v]=0;
	dfs1(v,0,x);
	v=to[x^1];
	for (i=1;i<=n;i++) if (vis[i]&&max(dp1[v],dp2[v])>max(dp1[i],dp2[i])) v=i;
	dfs2(u,0,x^1);
	dfs2(v,0,x);
	for (i=0;i<n;i++) c[i]=0;
	for (i=1;i<=n;i++) if (i!=u&&i!=v) c[dp[i]]++;
	for (i=n-2;i>=0;i--) c[i]+=c[i+1];
	for (i=n-1;i&&c[i-1]<k-1;i--);
	ans=min(ans,i);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T,i,u,v;
	for (scanf("%d%d",&c,&T);T;T--)
	{
		scanf("%d%d",&n,&k);
		tot=0;
		for (i=1;i<=n;i++) head[i]=-1;
		for (i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u); 
		}
		ans=n;
		if (c<=10||n<=1000) for (i=0;i<tot;i+=2) work(i);
		else for (i=-4;i<=4;i++) if (i&1) work(i+n/2);
		printf("%d\n",ans);
	}
	return 0;
}
