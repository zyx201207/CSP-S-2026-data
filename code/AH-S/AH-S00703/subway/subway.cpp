#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500001],l[500001][21],t[500001][21],top[500001],ds[501][501];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,tt;
			cin>>x>>tt;
			l[x][++top[x]]=i,t[x][top[x]]=tt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			ds[i][j]=1e15+1;
		ds[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int nowc=top[i];
		for(int j=1;j<nowc;j++)
		{
			for(int k=j+1;k<=nowc;k++)
			{
				int u=l[i][j],v=l[i][k];
				ds[u][v]=min(ds[u][v],t[i][j]+t[i][k]),ds[v][u]=min(ds[v][u],t[i][j]+t[i][k]);
				//cout<<i<<' '<<u<<' '<<v<<' '<<t[i][j]<<' '<<t[i][k]<<"\n";
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<ds[i][j]<<' ';
		cout<<"\n";
	}
	*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				ds[j][k]=min(ds[j][k],ds[j][i]+ds[i][k]);
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int minn=1e18+1;
		for(int i=1;i<=top[u];i++)
		{
			for(int j=1;j<=top[v];j++)
				minn=min(minn,t[u][i]+ds[l[u][i]][l[v][j]]+t[v][j]);
		}
		minn+=w[u]+w[v],cout<<minn<<"\n";
	}
	return 0;
}
