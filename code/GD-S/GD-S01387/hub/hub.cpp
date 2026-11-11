#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+9,inf=1e18;
ll id,Q;
ll n,k; 
vector<ll>G[N];
bool vis[N];
ll dep[N],f[N][22];
void dfs(ll u,ll fa)
{
	for(auto v:G[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		f[v][0]=u;
		for(int j=1;(1<<j)<=dep[v];j++)
		f[v][j]=f[f[v][j-1]][j-1];
		dfs(v,u);
	}
}
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=21;i>=0;i--)
	if(dep[x]-(1<<i)>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=21;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
ll Dis(ll x,ll y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
ll ans;
ll fa[12];
ll fz(ll x)
{
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void mj(ll id,ll cnt)
{
	if(cnt>k)return;
	if(id==n+1)
	{
		if(cnt!=k)return;
		ll ret=0,d[12];
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			d[i]=inf;
		}
		ll ltk=k;
		for(int u=1;u<=n;u++)
		{
			if(!vis[u])continue;
			for(auto v:G[u])
			{
				if(!vis[v])continue;
				ll fu=fz(u),fv=fz(v);
				if(fu==fv)continue;
				ltk--;
				fa[fu]=fv;
			}
		}
		if(ltk>2)return;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
			//	cout<<i<<" ";
				for(int j=1;j<=n;j++)
				d[j]=min(d[j],Dis(i,j));
			}
		}
		for(int i=1;i<=n;i++)
		ret=max(ret,d[i]);
	//	cout<<"&"<<ret<<"\n";
		ans=min(ans,ret);
		return;
	}
	vis[id]=0;
	mj(id+1,cnt);
	vis[id]=1;
	mj(id+1,cnt+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&id,&Q);
	while(Q--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n==k){puts("0");continue;}
		dep[1]=1;
		dfs(1,0);
		ans=inf;
		if(n<=10)
		{
			for(int i=1;i<=n;i++)
			vis[i]=0;
			mj(1,0);
			printf("%lld\n",ans);
		}
		
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			dep[i]=0;
			for(int j=0;j<=21;j++)
			f[i][j]=0;
		}
	}
	return 0;
}
