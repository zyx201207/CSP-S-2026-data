#include<bits/stdc++.h>
using namespace std;
struct edg{
	int u;
	int len;
};
int c,m,n,d,q;
int w[50005],a[50005],t[205][50005],st,ed,ans,sum;
bool vis[50005];
vector<edg>g[50005];
void dfs(int u,int fa,int go)
{
	vis[u]=1;
	if(u==ed)
	{
		ans=min(sum,ans);
		sum-=go;
		vis[u]=0;
		return ;
	}
	for(edg v:g[u])
	{
		if(!vis[v.u]&&v.u!=fa)
		{
			sum+=t[v.len][u];
			sum+=t[v.len][v.u];
			int z=t[v.len][u]+t[v.len][v.u];
			dfs(v.u,u,z);
		}
	}
	sum-=go;
	vis[u]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		memset(a,0,sizeof(a));
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[i][a[j]];
		}
		for(int l=1;l<=k;l++)
		{
			for(int r=l+1;r<=k;r++)
			{
				g[a[l]].push_back({a[r],i});
				g[a[r]].push_back({a[l],i});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=1e9,sum=0;
		cin>>st>>ed;
		dfs(st,st,0);
		cout<<ans+w[st]+w[ed]<<endl;
	}
	return 0;
}
