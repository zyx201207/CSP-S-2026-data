#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int M=5e5+10,N=510;
int C,n,m,sumd,q;
ll w[M],f[N][N];
vector<pair<int,ll>> ng[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>n>>m>>sumd>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,a,t;j<=k;j++)
			cin>>a>>t,ng[a].push_back({i,t});
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<ng[i].size();j++)
			for(int k=j+1;k<ng[i].size();k++)
			{
				int v1=ng[i][j].first,v2=ng[i][k].first;
				ll w1=ng[i][j].second,w2=ng[i][k].second;
				f[v1][v2]=min(f[v1][v2],w1+w2);
				f[v2][v1]=min(f[v2][v1],w1+w2);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<ng[x].size();i++)
			for(int j=0;j<ng[y].size();j++)
				ans=min(ans,f[ng[x][i].first][ng[y][j].first]+ng[x][i].second+ng[y][j].second);
		cout<<ans+w[x]+w[y]<<'\n'; 
	}
	return 0;
}
