#include<bits/stdc++.h>
#define int unsigned int
using namespace std;
typedef unsigned long long LL;
const int N=510,M=5e5+10;
const LL INF=1e18; 
int c,n,m,d,q,t[N][M],w[M];
LL g[N][N];
vector<int> id[M];//belong which line
vector<int> line[N];//have which station
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x>>t[i][x]; 
			id[x].push_back(i);
			line[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)g[i][j]=INF;
		g[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<line[i].size();j++)
		{
			int x=line[i][j];
			for(int k=0;k<id[x].size();k++)
			{
				int y=id[x][k];
				g[i][y]=g[y][i]=min(g[i][y],(LL)t[i][x]+t[y][x]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		LL res=INF;
		for(int i=0;i<id[l].size();i++)
		{
			for(int j=0;j<id[r].size();j++)
			{
				int x=id[l][i],y=id[r][j];
				res=min(res,(LL)t[x][l]+t[y][r]+g[x][y]);
			}
		}
		res+=(LL)w[l]+w[r];
		cout<<res<<endl;
	}
	return 0;
}
