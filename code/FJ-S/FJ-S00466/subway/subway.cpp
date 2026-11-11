#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int> >g[500005];
long long floyd[505][505];
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int i,j,k;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		int kk;
		cin>>kk;
		for(j=1;j<=kk;j++)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(floyd,0x3f,sizeof(floyd));
	for(i=1;i<=m;i++)
	{
		for(j=0;j<g[i].size();j++)
		{
			for(k=j+1;k<g[i].size();k++)
			{
				int u=g[i][j].first,v=g[i][k].first;
				if(g[i][j].second+g[i][k].second<floyd[u][v])
				{
					floyd[u][v]=floyd[v][u]=g[i][j].second+g[i][k].second;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		floyd[i][i]=0;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(floyd[i][j]>floyd[i][k]+floyd[k][j])
				{
					floyd[i][j]=floyd[i][k]+floyd[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int s,t;
		cin>>s>>t;
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(i=0;i<g[s].size();i++)
		{
			for(j=0;j<g[t].size();j++)
			{
				int u=g[s][i].first,v=g[t][j].first;
				int tu=g[s][i].second,tv=g[t][j].second;
				ans=min(ans,floyd[u][v]+tu+tv);
			}
		}
		cout<<w[s]+w[t]+ans<<"\n";
	}

	return 0;
}

