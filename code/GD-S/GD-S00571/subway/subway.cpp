#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e5 + 10; 
const int MAXN = 500+5; 
const long long INF = LONG_LONG_MAX;

long long w[MAXM];


long long c,n,m,d,q;

long long N,M;
long long dis[MAXM];

struct edge{
	long long v,w;
};
vector<edge> G[MAXM];

void addedge(long long u,long long v,long long w)
{
	G[u].push_back({v,w});
	G[v].push_back({u,w});
}

struct Node{
	long long ind,dis;
	bool operator <(const Node &a) const
	{
		return dis > a.dis;
	}
};

long long dij(long long st,long long ed)
{
	for(long long i=1;i<=N;i++)dis[i]=INF;	
	priority_queue<Node> q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty())
	{
		Node f=q.top();q.pop();
		long long u=f.ind;
		for(long long i=0;i<G[u].size();i++)
		{
			long long v=G[u][i].v,w=G[u][i].w;
			
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[ed];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	long long t;
	for(long long i=1;i<=m;i++)cin>>w[i]; 
	for(long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			long long cstation;
			cin>>cstation>>t; 
			addedge(m+i,cstation,t); 
		}
	}
	N=m+n;
	for(long long i=1;i<=q;i++)
	{
		long long x,y,ans=INF;
		cin>>x>>y;
		ans=dij(x,y);
		cout<<ans+w[x]+w[y]<<endl;
	}
	
	return 0;	
}  
