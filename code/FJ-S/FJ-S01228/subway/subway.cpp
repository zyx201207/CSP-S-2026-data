#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int MAXN=1e6+10;
vector <pair<long long,int>> g[MAXN];
long long dis[MAXN];
int tot;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<long long> w(m+1);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	tot=m;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int mid=++tot;
		for(int j=1;j<=k;j++)
		{
			int a;
			long long t;
			cin>>a>>t;
			int p=++tot;
			g[a].emplace_back(t,p);
			g[p].emplace_back(t,a);
			g[p].emplace_back(0LL,mid);
			g[mid].emplace_back(0LL,p);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		fill(dis,dis+tot+1,INF);
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
		dis[x]=0;
		pq.emplace(0LL,x);
		while(!pq.empty())
		{
			auto cur=pq.top();
			pq.pop();
			long long dist_u=cur.first;
			int u=cur.second;
			if(dist_u>dis[u])
			{
				continue;
			}
			for(auto edge:g[u])
			{
				long long len=edge.first;
				int v=edge.second;
				if(dis[v]>dist_u+len)
				{
					dis[v]=dist_u+len;
					pq.emplace(dis[v],v);
				}
			}
		}
		long long ans=dis[y]+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

