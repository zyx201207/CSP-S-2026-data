#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],t[500010][510];
vector<vector<int> > a;
vector<vector<int> > ans;
void dfs(int g,int f,int u,int s)
{
	for(int v=u;v<=m;v++)
	{
		if(a[u][v]!=0)
		{
			int x=t[u][a[u][v]]+t[v][a[u][j]];
			if(x==ans[u][v])
			{
				return;
			}
			if(ans[u][v]!=0)
			{
				x=max(x,ans[u][v]);
			}
			ans[u][v]=x;
			ans[j][u]=ans[u][v];
			dfs(g,u,v,s+x);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,f;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			cin>>t[x][k];
			if(j>=2)
			{
				a[f][x]=k;
				a[x][f]=k;
			}
			f=x;
		}
	}
	for(int i=1;i<m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
				int x=t[i][a[i][j]]+t[j][a[i][j]];
				if(x==ans[i][j])
				{
					continue;
				}
				if(ans[i][j]!=0)
				{
					x=max(x,ans[i][j]);
				}
				ans[i][j]=x;
				ans[j][i]=ans[i][j];
				dfs(i,i,j,ans[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+ans[x][y];
	}
	return 0;
}
