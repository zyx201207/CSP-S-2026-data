#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N=510,M=5e5+510,K=2e3+10,inf=0x3f3f3f3f3f3f3f3f,P=3e4+10; 
int c,n,m,d,q;
int w[M];
int dist[K][K],dist2[P];
int t[3][M],cnt[M];
bool vis[M];
vector<int> g[N];
struct node
{
	int to,w;
};
vector<node> vec[M];
void dij_1(int x)
{
	for(int i=1;i<=m+n;i++)
	{
		dist[x][i]=inf;
	}
	for(int i=1;i<=m+n;i++)
	{
		vis[i]=0;	
	} 
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,x});
	dist[x][x]=0;
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int u=t.y;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<vec[u].size();i++)
		{
			int v=vec[u][i].to,w=vec[u][i].w;
			if(dist[x][v]>dist[x][u]+w)
			{
				dist[x][v]=dist[x][u]+w;
				q.push({dist[x][v],v});
			}
		}
	}
}
void dij_2(int x)
{
	for(int i=1;i<=m+n;i++)
	{
		dist2[i]=inf;
	}
	for(int i=1;i<=m+n;i++)
	{
		vis[i]=0;	
	} 
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,x});
	dist2[x]=0;
	while(q.size())
	{
		auto t=q.top();
		q.pop();
		int u=t.y;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=0;i<vec[u].size();i++)
		{
			int v=vec[u][i].to,w=vec[u][i].w;
			if(dist2[v]>dist2[u]+w)
			{
				dist2[v]=dist2[u]+w;
				q.push({dist2[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int sz;
		cin>>sz;
		for(int j=1;j<=sz;j++)
		{
			int l,r;
			cin>>l>>r;
			g[i].push_back(l);
			vec[m+i].push_back({l,r});
			vec[l].push_back({m+i,r});
		}
	}
	if(m<=1000)
	{
		for(int i=1;i<=m;i++)
		{
			dij_1(i);
		}
	}
	int k=q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(m<=1000)
		{
			cout<<dist[x][y]+w[x]+w[y]<<endl;
			continue;
		}
		if(k<=2000)
		{
			dij_2(x);
			cout<<dist2[y]+w[x]+w[y]<<endl;
			continue;
		}
	}
	return 0;
}
/*

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
2 3


*/
