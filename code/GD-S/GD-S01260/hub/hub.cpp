#include<bits/stdc++.h>
using namespace std;
#define int long long
int pd[21],dis[21][21],f[21],rt;
int n,k,ans;
vector<int> g[21];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void dg(int x,int k)
{
//	printf("%lld ",x);
	if(x==n+1)
	{
		if(k!=0)return;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++)
			if(pd[i])
			{
//				printf("%lld ",i);
				for(auto v:g[i])
				{
					if(!pd[v])continue;
					int fx=find(v),fy=find(i);
					if(fx!=fy)
						f[fx]=fy;
				}
			}
		for(int i=1;i<=n;i++)
			f[i]=find(i);
		set<int> use;
		for(int i=1;i<=n;i++)
			if(pd[i])
				use.insert(f[i]);
		if(use.size()>2)return;
		int lans=0;
		for(int i=1;i<=n;i++)
		{
			int lx=LLONG_MAX;
			for(int j=1;j<=n;j++)
				if(pd[j])
					lx=min(lx,dis[i][j]);
			lans=max(lans,lx);
		}
//		printf("%lld\n",lans);
		ans=min(ans,lans);
		return;
	}
	pd[x]=0;
	dg(x+1,k);
	pd[x]=1;
	dg(x+1,k-1);
}
void init(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa)continue;
		dis[rt][v]=dis[rt][u]+1;
		init(v,u);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
			g[i].clear();
		ans=LLONG_MAX;
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%lld%lld",&x,&y),g[x].push_back(y),g[y].push_back(x);
		}
		for(int i=1;i<=n;i++)pd[i]=0;
		for(int i=1;i<=n;i++)
			rt=i,init(i,0);
		dg(1,k);
		printf("%lld\n",ans);
	}
	return 0;
}
