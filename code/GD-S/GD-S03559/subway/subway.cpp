#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],disn[505][505],ans;
long long vis[505],inq[505];
vector<pair<int,int>>adjm[500005];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(int s)
{
	priority_queue<pair<long long,int>>sq;
	for(int i=1;i<=n;i++)
		if(i!=s)sq.push({-disn[s][i],i});
	while(!sq.empty())
	{
		auto[t,u]=sq.top();
		sq.pop();
		if(vis[u])continue;
		t=-t,vis[u]=1;
		for(int v=1;v<=n;v++)
		{
			if(vis[v]||disn[u][v]+t>=disn[s][v])continue;
			disn[s][v]=disn[u][v]+t;
			disn[v][s]=disn[u][v]+t;
			sq.push({-disn[s][v],v});
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k;i<=n;i++)
	{
		k=read();
		for(int j=1,a,t;j<=k;j++)
		{
			a=read(),t=read();
			adjm[a].push_back({i,t});
		}
	}
	memset(disn,0x3f,sizeof(disn));
	for(int i=1;i<=n;i++)disn[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(auto[u,t1]:adjm[i])
		{
			for(auto[v,t2]:adjm[i])
			{
				disn[u][v]=min(disn[u][v],(t1+t2)*1ll);
				disn[v][u]=min(disn[v][u],(t1+t2)*1ll);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	for(int i=1,x,y;i<=q;i++)
	{
		x=read(),y=read();
		ans=1e18;
		for(auto[u,t1]:adjm[x])
		{
			for(auto[v,t2]:adjm[y])
			{
				ans=min(ans,disn[u][v]+t1+t2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
