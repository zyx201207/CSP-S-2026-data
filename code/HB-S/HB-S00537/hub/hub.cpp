#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,k,d[100010],f[100010][21];
int sm=0,vis[100010],vis2[100010],ans;
vector<int> e[100010];
void dfs(int u,int fa)
{
	d[u]=d[fa]+1,f[u][0]=fa;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
void dfs1(int u,int fa)
{
	vis2[u]=1;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa||vis[v]==0) continue;
		dfs1(v,u);
	}
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=20;i>=0;i--) if(d[u]-(1<<i)>=d[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
void dfsa(int k0,int ns)
{
	if(ns>k) return ;
	if((n-k0+1)+ns<k) return ;
	if(k0>n)
	{
		if(ns!=k) return ;
		sm=0;
		for(int i=1;i<=n;i++) vis2[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1&&vis2[i]==0)
			{
				sm++;
				dfs1(i,0);
			}
		}
		int res1=0,res2=0;
		if(sm>2) return ;
		//for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
		//cout<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1) continue;
			res1=1e9;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==0) continue;
				int diss=d[i]+d[j]-2*(d[lca(i,j)]);
				res1=min(res1,diss);
			}
			//cout<<res1<<' ';
			res2=max(res1,res2);
		}
		//cout<<endl;
		ans=min(ans,res2);
		return ;
	}
	vis[k0]=1;
	dfsa(k0+1,ns+1);
	vis[k0]=0;
	dfsa(k0+1,ns);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=1e9;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		d[0]=0;
		dfs(1,0);
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) cout<<i<<' '<<j<<' '<<lca(i,j)<<endl;
		}*/
		dfsa(1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) 
		{
			e[i].clear();
		}
	}
	return 0;
}
