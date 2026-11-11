#include<bits/stdc++.h>
#define int long long
using namespace std;

const int dd=2e4+5;
int w[dd],k[505],a[505][dd],t[505][dd],x[100005],y[100005];
struct edge
{
	int v;
	int w;
};
vector<edge> to[dd];
int f[2005][2005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	//create
	for(int k1=1;k1<=n;k1++)
	{
		for(int i=1;i<=k[k1];i++)
		{
			for(int j=i+1;j<=k[k1];j++)
			{
				to[a[k1][i]].push_back({a[k1][j],t[k1][i]+t[k1][j]});
				to[a[k1][j]].push_back({a[k1][i],t[k1][i]+t[k1][j]});
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j) f[i][j]=0;
			else f[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)(to[i].size());j++)
		{
			f[i][to[i][j].v]=to[i][j].w;
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}/*
	for(int i=1;i<=m;i++)
	{
		cout<<i<<"   ";
		for(int j=0;j<to[i].size();j++)
		{
			cout<<to[i][j].v<<' '<<to[i][j].w<<"  ";
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++)
	{
		cout<<f[x[i]][y[i]]+w[x[i]]+w[y[i]]<<endl;
	}
	return 0;
}
