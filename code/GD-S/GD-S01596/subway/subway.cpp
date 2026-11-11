#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>> p[500010];
int f[510][510],w[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			p[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<p[i].size();j++)
		for(int k=j+1;k<p[i].size();k++)
		{
			int x=p[i][j].first,tx=p[i][j].second,y=p[i][k].first,ty=p[i][k].second;
			f[x][y]=min(f[x][y],tx+ty);
			f[y][x]=min(f[y][x],tx+ty);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto px:p[x]) for(auto py:p[y]) ans=min(ans,px.second+py.second+f[px.first][py.first]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
