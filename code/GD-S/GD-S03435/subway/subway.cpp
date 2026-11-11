#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>> vec[500505];
ll f[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			vec[a].push_back({m+i,t});
			vec[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=inf;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int siz=vec[i].size();
		for(int j=0;j<siz;j++)
		{
			for(int k=j+1;k<siz;k++)
			{
				int a=vec[i][j].first-m,b=vec[i][k].first-m;
				f[a][b]=f[b][a]=min(f[a][b],1ll*vec[i][j].second+1ll*vec[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll cost=inf;
		int lenx=vec[x].size(),leny=vec[y].size();
		for(int i=0;i<lenx;i++)
		{
			for(int j=0;j<leny;j++)
			{
				int a=vec[x][i].first-m;
				int b=vec[y][j].first-m;
				ll vi=vec[x][i].second;
				ll vj=vec[y][j].second;
				cost=min(cost,vi+vj+f[a][b]);
			}
		}
		cout<<cost+w[x]+w[y]<<"\n";
	}
	return 0;
}
