#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,inf=1e13;
int c,t,n,k,u,v,f[N],cnt,s[N];
int mp[N][N],dep[N],fa[N][20];
int lt,vis[N],ma,mi,ans,m[N];
int tj[N],son[N];
vector<int> e[N];
void dfs(int u,int fat)
{
	dep[u]=dep[fat]+1;
	fa[u][0]=fat;
	son[u]=v;
	for(int i=1;i<=19;i++)  fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:e[u])
	{
		if(v==fat)  continue;
		dfs(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])  swap(u,v);
	for(int g=19;g>=0;g--)  if(dep[u]-(1<<g)>=dep[v])  u=fa[u][g];
	if(u==v)  return u;
	for(int g=19;g>=0;g--)
	{
		if(fa[u][g]!=fa[v][g])
		{
			u=fa[u][g];
			v=fa[v][g];
		}
	}
	return fa[u][0];
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)  e[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			mp[u][v]=1;
			mp[v][u]=1;
		}
		dfs(1,0);
		ans=inf;
		for(int now=1;now<(1<<n);now++)
		{
			cnt=0;
			for(int i=1;i<=n;i++)  
			{
				vis[i]=0;
				f[i]=i;
				m[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				if(now&(1<<(i-1)))  
				{
					cnt++;
					s[cnt]=i;
					vis[i]=1;
				}
			}
			if(cnt!=k)  continue;
			for(int i=1;i<=cnt;i++)
			{
				if(tj[s[i]])  continue;
				u=s[i];
				tj[u]=s[i];
				while(u<n&&son[u]>0)  u=son[u],tj[u]=s[i];
			}
			lt=0;
			for(int i=1;i<=cnt;i++)
			{
				if(!m[tj[s[i]]])  lt++; 
				m[tj[s[i]]]=1;
			}
			if(lt>2)  continue;
			ma=0;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])  continue;
				mi=inf;
				for(int j=1;j<=cnt;j++)  
				{
					if(s[j]==i)  continue;
					mi=min(mi,dep[s[j]]+dep[i]-2*dep[lca(s[j],i)]);
				}
				ma=max(ma,mi);
			}
			ans=min(ans,ma);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
