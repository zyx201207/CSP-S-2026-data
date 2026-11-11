#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
const int N=5e5+5;
const int inf=1e18;
int c,n,m,d,q,w[N],k[505],x,y;
vector<int> a[505],t[505];
vector<pair<int,int>> e[N];
int dis[1005][1005],dp[1005],vis[1005],st[1005][505];
struct node
{
	int dis,u,lst;
	bool operator<(const node&o) const
	{
		return dis>o.dis;
	}
};
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	faster;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x;
			a[i].push_back(x);
			cin>>y;
			t[i].push_back(y);
			st[x][i]=y;
		}
		for(int j=1;j<k[i];j++)
		{
			int u=a[i][j-1],v=a[i][j];
			e[u].push_back({v,i});
			e[v].push_back({u,i});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!st[i][j]) continue;
			int line=j,cost=st[i][j];
			for(int k=1;k<=m;k++) dp[k]=inf;
			for(int k=1;k<=m;k++) vis[k]=0;
			priority_queue<node> qq;
			dp[i]=0;
			qq.push({dp[i],i,line});
			while(qq.size())
			{
				node tmp=qq.top();
				qq.pop();
				int u=tmp.u,lst=tmp.lst;
				if(vis[u]) continue;
				vis[u]=1;
				for(auto g:e[u])
				{
					int v=g.first,nline=g.second;
					if(vis[v]) continue;
					if(u==i&&nline!=j) continue;
					int ncost=0;
					if(u!=i&&nline!=lst) ncost=st[u][lst]+st[u][nline];
					if(dp[v]>dp[u]+ncost)
					{
						dp[v]=dp[u]+ncost;
						qq.push({dp[v],v,nline});
					}
					dis[i][v]=min(dis[i][v],dp[v]+cost+st[v][nline]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		cout<<min(dis[x][y],dis[y][x])+w[x]+w[y]<<'\n';
	}
	return 0;
}