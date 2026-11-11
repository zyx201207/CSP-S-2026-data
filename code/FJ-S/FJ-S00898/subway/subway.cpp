#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,u,v;
long long f[510][100010],t[510][100010],ans,w[100010];
int a[510][100010],k[510],vis[510][100010];
void dfs(int x,int l,long long s)
{
	if(x==v)
	{
		if(ans==-1)
		{
			ans=s+t[l][vis[l][x]];
		}
		else ans=min(s+t[l][vis[l][x]],ans);
		return;
	}
	if(s>=ans&&ans!=-1)
	{
		return;
	}
	for(int i=1;i<=k[l];i++)
	{
		if(x!=a[l][i]&&(s<f[l][a[l][i]]||f[l][a[l][i]]==-1))
		{
			f[l][a[l][i]]=s;
			dfs(a[l][i],l,s);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i][x]!=0&&l!=i&&(s+t[l][vis[l][x]]+t[i][vis[i][x]]<f[i][x]||f[i][x]==-1))
		{
			f[i][x]=s+t[l][vis[l][x]]+t[i][vis[i][x]];
			dfs(x,i,s+t[l][vis[l][x]]+t[i][vis[i][x]]);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			vis[i][a[i][j]]=j;
		}
	}
	while(q--)
	{
		ans=-1;
		cin>>u>>v;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			f[i][j]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i][u]!=0)
			{
				dfs(u,i,t[i][vis[i][u]]);
			}
		}
		cout<<ans+w[u]+w[v]<<endl;		
	}
}
