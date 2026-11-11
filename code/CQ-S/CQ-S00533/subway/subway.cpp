#include<bits/stdc++.h>
using namespace std;
namespace Ganlai
{
#define int long long
	const int N=500+1,M=2e4+1,Q=1e5+1,INF=9e18;
	int n,m,d,q;
	struct Edge
	{
		int p,t,w;
		inline bool operator <(const Edge &A) const
		{
			return w>A.w;
		}
	};
	vector<Edge> edges[N][M];
	inline void addedge1(const int &u,const int &v,const int &c)
	{
		edges[u][c].push_back({v,c,0}),
		edges[v][c].push_back({u,c,0});
	}
	inline void addedge2(const int &u,const int &w,const int &c)
	{
//		printf("(%lld,%lld) - (%lld,%lld) %lld\n",u,c,u,0,w);
		edges[u][c].push_back({u,0,w}),
		edges[u][0].push_back({u,c,w});
	}
	int w[M];
	inline void dij(const int &st,vector<vector<int>> &dist)
	{
		priority_queue<Edge> q;
		dist[st][0]=w[st];
		q.push({st,0,w[st]});
		while(!q.empty())
		{
			const int p=q.top().p,t=q.top().t,w=q.top().w;
//			printf("%lld %lld %lld\n",p,t,w);
			q.pop();
			if(w>dist[p][t])
				continue;
			for(const Edge &i:edges[p][t])
			{
//				printf(">%lld %lld %lld\n",dist[i.p][i.t],dist[p][t],i.w);
				if(dist[i.p][i.t]>dist[p][t]+i.w)
					dist[i.p][i.t]=dist[p][t]+i.w,
					q.push({i.p,i.t,dist[i.p][i.t]});
			}
		}
	}
	vector<int> ask[M];
	pair<int,int> num[Q];
	map<pair<int,int>,int> ans;
	void main()
	{
		scanf("%*d%lld%lld%lld%lld",&n,&m,&d,&q);
		for(int i=1;i<=m;++i)
			scanf("%lld",w+i);
		for(int i=1,k;i<=n;++i)
		{
			scanf("%lld",&k);
			for(int j=1,pa=0,a,t;j<=k;++j)
			{
				scanf("%lld%lld",&a,&t);
				if(pa!=0)
					addedge1(pa,a,i);
				addedge2(a,t,i);
				pa=a;
			}
		}
//		for(int i=1;i<=q;++i)
//		{
//			vector<vector<int>> dist(m+1,vector<int>(n+1,INF));
//			int x,y;
//			scanf("%lld%lld",&x,&y);
//			dij(x,dist);
//			printf("%lld\n",dist[y][0]+w[y]);
//		}
		for(int i=1;i<=q;++i)
		{
			int x,y;
			scanf("%lld%lld",&x,&y);
			ask[x].push_back(y),ask[y].push_back(x);
			num[i]={x,y};
		}
//		sort(ask+1,ask+m+1,[](const vector<int> &A,const vector<int> &B){return A.size()>B.size();});
		for(int i=1;i<=m;++i)
		{
			vector<int> pre;
//			printf("<");
			for(const int &j:ask[i])
				if(!ans[{i,j}]||!ans[{j,i}])
					pre.push_back(j);
//			printf(">\n");
			if(pre.empty())
				continue;
			vector<vector<int>> dist(m+1,vector<int>(n+1,INF));
			dij(i,dist);
			for(const int &j:pre)
				ans[{i,j}]=ans[{j,i}]=dist[j][0]+w[j];
		}
		for(int i=1;i<=q;++i)
			printf("%lld\n",ans[num[i]]);
	}
#undef int
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Ganlai::main();
	return 0;
}

