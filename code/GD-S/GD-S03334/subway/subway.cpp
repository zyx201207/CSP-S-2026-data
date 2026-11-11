#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q;
int sk[505];
int dis[505][505];
int insub[N];//地铁到站厅的时间 
struct node
{
	int v,w;
};
vector<node>belong[N];//属于哪些地铁,到地铁的距离 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c >> n >> m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin >> insub[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> sk[i];
		for(int j=1;j<=sk[i];j++)
		{
			int a,t;
			cin >>a >> t;
			belong[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<belong[i].size();j++)
		{
			for(int k=j+1;k<belong[i].size();k++)
			{
				int x=belong[i][j].v,y=belong[i][k].v,len=belong[i][j].w+belong[i][k].w;
				dis[x][y]=min(dis[x][y],len);
				dis[y][x]=min(dis[y][x],len);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		int ans=9e18;
		for(int i=0;i<belong[x].size();i++)
		{
			for(int j=0;j<belong[y].size();j++)
			{
				int start=belong[x][i].v,end=belong[y][j].v,w=belong[x][i].w+belong[y][j].w;
				ans=min(ans,dis[start][end]+w+insub[x]+insub[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
