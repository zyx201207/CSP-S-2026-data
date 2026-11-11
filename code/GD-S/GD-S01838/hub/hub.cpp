#include<bits/stdc++.h>
using namespace std;
long long type,T,dp[1005][25],n,dep[1005],lca[1005][1005],k,ans;
vector<long long>E[1005],h;
bool c[1005],d[1005];
void dffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffs(long long u,long long fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa)
{
	dep[u]=dep[fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa]+1;
	dp[u][0]=fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa;
	for(auto v:E[u])
	{
		if(v==fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffa)
			continue;
		dffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffs(v,u);
	}
}
long long lccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccca(long long u,long long v)
{
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=20;i>=0;i--)
		if(dep[dp[u][i]]>=dep[v])
			u=dp[u][i];
	if(u==v)
		return u;
	for(int i=20;i>=0;i--)
		if(dp[u][i]!=dp[v][i])
		{
			u=dp[u][i];
			v=dp[v][i];
		}
	return dp[u][0];
}
void bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbl(long long x)
{
	queue<long long>q;
	q.push(x);
	c[x]=1;
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		for(auto v:E[u])
			if(!c[v]&&d[v])
			{
				c[v]=1;
				q.push(v);
			}
	}
}
void geeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeet(long long x,long long y)
{
	if(x==n&&y<k)
		return;
	if(y==k)
	{
		long long cnt=0;
		for(auto i:h)
			d[i]=1;
		for(auto i:h)
			if(!c[i])
			{
				cnt++;
				bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbl(i);
			}
		if(cnt<=2)
		{
			long long maxn=0;
			for(int t=1;t<=n;t++)
			{
				long long minn=1e18;
				for(auto i:h)
					minn=min(minn,dep[i]+dep[t]-2*dep[lca[i][t]]);
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);
		}
		for(auto i:h)
			d[i]=c[i]=0;
		return;
	}
	h.push_back(x+1);
	geeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeet(x+1,y+1);
	h.pop_back();
	geeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeet(x+1,y);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&type,&T);
	while(T--)
	{
		ans=1e18;
		for(int i=1;i<=n;i++)
			E[i].clear();
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++)
		{
			long long u,v;
			scanf("%lld%lld",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		dffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffs(1,1);
		for(int i=1;i<=20;i++)
			for(int t=1;t<=n;t++)
				dp[t][i]=dp[dp[t][i-1]][i-1];
		for(int i=1;i<=n;i++)
			for(int t=1;t<=n;t++)
				lca[i][t]=lccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccca(i,t);
		h.clear();
		geeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeet(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
