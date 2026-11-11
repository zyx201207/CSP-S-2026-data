#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=505,M=5e5+5,MAXN=1e5+5;
int c,n,m,d,qr;
int wr[M],all[N];
int val[N][N],dis[N],mn[N][N];
bool vis[N];
vector<int>a[N];
vector<int>t[N];
vector<pii>line[M];
vector<pii>edge[N];
struct node
{
	int u,va;
	bool operator <(const node &o) const
	{
		return va>o.va;
	}
};
void dij(int s)
{
	priority_queue<node>q;
	for(int i=1;i<=n;i++) dis[i]=1e18;
	for(int i=1;i<=n;i++) vis[i]=0;
	dis[s]=0;
	q.push((node){s,dis[s]});
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,w=edge[u][i].second;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push((node){v,dis[v]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qr;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) val[i][j]=1e18;
	}
	for(int i=1;i<=m;i++) cin>>wr[i];
	for(int i=1;i<=n;i++)
	{
		cin>>all[i];
		for(int j=1;j<=all[i];j++)
		{
			int x,y;
			cin>>x>>y;
			line[x].push_back({i,j});
			a[i].push_back(x);
			t[i].push_back(y);
		}
	} 
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<line[i].size();j++)
		{
			for(int k=j+1;k<line[i].size();k++)
			{
				int u=line[i][j].first,v=line[i][k].first;
				int p1=line[i][j].second,p2=line[i][k].second;
				val[u][v]=min(val[u][v],t[u][p1-1]+t[v][p2-1]);
				val[v][u]=val[v][u];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(val[i][j]!=1e18)
			{
				edge[i].push_back({j,val[i][j]});
				edge[j].push_back({i,val[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
		for(int j=1;j<=n;j++) mn[i][j]=dis[j];
	}
	for(int i=1;i<=qr;i++)
	{
		int x,y,ans=1e18,cnt=0;
		cin>>x>>y;
		for(int j=0;j<line[x].size();j++)
		{
			for(int k=0;k<line[y].size();k++)
			{
				int u=line[x][j].first,v=line[y][k].first;
				int p1=line[x][j].second,p2=line[y][k].second;
				if(ans>mn[u][v])
				{
					ans=mn[u][v];
					cnt=t[u][p1-1]+t[v][p2-1];
				}	
			}
		}
		ans+=(wr[x]+wr[y]+cnt);
		cout<<ans<<"\n";
	}
	return 0;
}