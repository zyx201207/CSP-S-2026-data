#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5,Q=1e5+5;
const ll inf=1e18;
int c,n,m,d,q;
ll w[M];
vector<pair<int,ll> >g[N+M];
struct Node
{
	int x,y,id;
	bool operator <(const Node &o)const
	{
		if(x==o.x)
			return y<o.y;
		return x<o.x;
	}
};

ll ans[Q];
ll dis[N+M];

void dij(int st)
{
	for(int i=1;i<=n+m;i++)
		dis[i]=inf;
	dis[st]=0;
	priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	pq.push({0,st});
	while(!pq.empty())
	{
		ll d=pq.top().first,u=pq.top().second;
		pq.pop();
		
		if(d>dis[u])
			continue;
			
		for(auto tmp:g[u])
		{
			int v=tmp.first;ll w=tmp.second;
			
			if(dis[v]>d+w)
			{
				dis[v]=d+w;
				pq.push({dis[v],v});
			}
		}
	}
} 

ll s1dis[N][N];

void solve1()
{
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;ll t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	memset(s1dis,0x3f,sizeof(s1dis));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int u=g[i][j].first; ll w1=g[i][j].second;
			for(int jj=0;jj<g[i].size();jj++)
			{
				if(j==jj)continue;
				int v=g[i][jj].first; ll w2=g[i][jj].second;
				s1dis[u][v]=min(s1dis[u][v],w1+w2);
				s1dis[v][u]=min(s1dis[v][u],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		s1dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				s1dis[i][j]=min(s1dis[i][j],s1dis[i][k]+s1dis[k][j]);
			}
		}
	}
	
	while(q--)
	{
		int x,y;cin>>x>>y;
		ll ans=w[x]+w[y];
		ll mn=inf;
		for(pair<int,int>tmp1:g[x])
		{
			int u=tmp1.first;ll w1=tmp1.second;
			for(pair<int,int>tmp2:g[y])
			{
				int v=tmp2.first;ll w2=tmp2.second;
				mn=min(mn,s1dis[u][v]+w1+w2);
			}
		}
		ans=ans+mn;
		cout<<ans<<"\n";
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)
		cin>>w[i];
	
	if(c==22 or c==23)
	{
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a;ll t;
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	vector<Node >qry;
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		if(x>y)swap(x,y);
		qry.push_back({x,y,i});
	}
	sort(qry.begin(),qry.end());
	
	for(int i=0;i<q;)
	{
		int x=qry[i].x;
		dij(x);
		
		while(i<q and qry[i].x==x)
		{
			int y=qry[i].y,id=qry[i].id;
			ans[id]=dis[y];
			ans[id]+=w[x]+w[y];
			i++;
		}	
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
	return 0;
}
