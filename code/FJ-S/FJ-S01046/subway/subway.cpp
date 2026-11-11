#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
using namespace std;
int id,n,m,d,q,w[M],f[N][N];
vector<pair<int,int> >v[M];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				int x=v[i][j].first,y=v[i][k].first,z=v[i][j].second+v[i][k].second;
				f[x][y]=f[y][x]=min(f[x][y],z);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto i:v[x])
		{
			for(auto j:v[y])
			{
				ans=min(ans,f[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

