#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=500010,N=510;
int w[M];
vector<int> a[N],t[N];
struct edge{
	int v,w;
};
bool vis[M];
bool operator>(edge x,edge y)
{
	return x.w>y.w;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		a[i].resize(k+5),t[i].resize(k+5);
		a[i][0]=k;
		for(int j=1;j<=k;++j) cin>>a[i][j]>>t[i][j];
	}
	if(7<=C&&C<=11)
	{
		vector<vector<edge> > g(m+5);
		vector<vector<int> > dis(m+5,vector<int> (m+5,1e18));
//		vector<int> vis(m+5);
		for(int i=1;i<=n;++i)
		{
			if(a[i][2])
			{
				int x=a[i][1],y=a[i][2];
				int p=t[i][1]+t[i][2];
				g[x].push_back({y,p});
				g[y].push_back({x,p});
			}
		}
		for(int i=1;i<=m;++i)
		{
			priority_queue<edge,vector<edge>,greater<edge> > q;
			memset(vis,0,sizeof(vis));
			q.push({i,0});
			dis[i][i]=0;
			while(!q.empty())
			{
				edge t=q.top();
				q.pop();
				int u=t.v;
				if(vis[u]) continue;
				vis[u]=1;
				for(auto v:g[u])
				{
					if(dis[i][u]+v.w<dis[i][v.v])
					{
						dis[i][v.v]=dis[i][u]+v.w;
						q.push({v.v,dis[i][v.v]});
					}
				}
			}
//			for(int j=1;j<=m;++j) cerr<<dis[i][j]<<' ';
//			cerr<<'\n';
		}
		while (q--)
		{
			int x,y;
			cin>>x>>y;
//			cerr<<w[x]<<' '<<dis[x][y]<<' '<<w[y]<<'\n';
			cout<<w[x]+dis[x][y]+w[y]<<'\n';
		}
		return 0;
	}
	if(C<=6)
	{
		vector<vector<edge> > g(m+5);
		vector<vector<int> > dis(m+5,vector<int>(m+5,1e18));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=a[i][0];++j)
			{
				for(int k=j+1;k<=a[i][0];++k)
				{
					int x=a[i][j],y=a[i][k],p=t[i][j]+t[i][k];
					g[x].push_back({y,p});
					g[y].push_back({x,p});
				}
			}
		}
		for(int i=1;i<=m;++i)
		{
			priority_queue<edge,vector<edge>,greater<edge> > q;
			memset(vis,0,sizeof(vis));
			q.push({i,0});
			dis[i][i]=0;
			while(!q.empty())
			{
				edge t=q.top();
				q.pop();
				int u=t.v;
				if(vis[u]) continue;
				vis[u]=1;
				for(auto v:g[u])
				{
					if(dis[i][u]+v.w<dis[i][v.v])
					{
						dis[i][v.v]=dis[i][u]+v.w;
						q.push({v.v,dis[i][v.v]});
					}
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
//			cerr<<dis[x][y]<<'\n';
			cout<<w[x]+dis[x][y]+w[y]<<'\n';
		}
		return 0;
	}
	if(C==20||C==21)
	{
		unordered_map<int,int> l1,l2;
		int sum=1e18;
		vector<vector<int> > g(m+5,vector<int> (5));
		for(int i=1;i<=a[1][0];++i)
		{
			l1[a[1][i]]=1;
			g[a[1][i]][1]=t[1][i];
		}
		for(int i=1;i<=a[2][0];++i)
		{
			l2[a[2][i]]=1;
			g[a[2][i]][2]=t[2][i];
		}
		for(int i=1;i<=m;++i)
		{
			if(g[i][1]&&g[i][2])
			{
				int x=g[i][1]+g[i][2];
//				cerr<<i<<' '<<g[i][1]<<' '<<g[i][2]<<' '<<x<<'\n';
				sum=min(sum,x);
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int k=0;
			if(l1[x]&&l1[y]) k=g[x][1]+g[y][1];
			else if(l2[x]&&l2[y]) k=g[x][1]+g[y][1];
			else if(l2[x]&&l1[y]) k=sum+g[x][2]+g[y][1];
			else if(l1[x]&&l2[y]) k=sum+g[x][1]+g[y][2];
//			cerr<<sum<<' '<<k<<'\n';
			cout<<k+w[x]+w[y]<<'\n';
		}
		return 0;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}

