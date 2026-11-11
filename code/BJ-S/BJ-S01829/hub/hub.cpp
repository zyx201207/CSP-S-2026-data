#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e6+5;
const int inf=1e9+5;
int c,t,n,k,u,v,dep[N],f[N][22],b[N],ff[N],use[N],dis[N],res;
vector<int> e[N];
struct node
{
	int u,v;
}edge[N];
void dfs0(int fa,int u)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs0(u,v);
	}
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		dep[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<22;j++) f[i][j]=0;
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=21;i>=0;i--)
	{
		if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	}
	if(u==v) return u;
	for(int i=21;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
int caldis(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int find(int x)
{
	if(ff[x]==x) return x;
	return ff[x]=find(ff[x]);
}
void dfs(int dep)
{
	if(dep>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(use[i]) cnt++;
		}
		if(cnt!=k) return;
		for(int i=1;i<=n;i++) ff[i]=i;
		for(int i=1;i<n;i++)
		{
			int u=edge[i].u,v=edge[i].v;
			if(use[u]&&use[v])
			{
				int rtu=find(u),rtv=find(v);
				if(rtu==rtv) continue;
				ff[rtu]=rtv;
			}
		}
		for(int i=1;i<=n;i++) b[i]=0;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!use[i]) continue;
			int rt=find(i);
			b[rt]++;
			if(b[rt]==1) cnt++;
		}
		if(cnt>2) return;
		for(int i=1;i<=n;i++) dis[i]=inf;
		for(int i=1;i<=n;i++)
		{
			if(use[i]) dis[i]=0;
			else
			{
				for(int j=1;j<=n;j++)
				{
					if(use[j]) dis[i]=min(dis[i],caldis(i,j));
				}
			}
		}
		int tmp=0;
		for(int i=1;i<=n;i++) tmp=max(tmp,dis[i]);
		res=min(res,tmp);
		return;
	}
	use[dep]=0;
	dfs(dep+1);
	use[dep]=1;
	dfs(dep+1);
}
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		edge[i]={u,v};
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs0(0,1);
	for(int i=1;i<22;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	res=inf;
	dfs(1);
	cout<<res<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	faster;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}