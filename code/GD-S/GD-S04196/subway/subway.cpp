#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,n,m,d,Q;
ll w[500010];
struct node{
	int a;
	ll t;
};
struct edge{
	int u;
	ll w;
	bool operator<(const edge &a) const{
		return w>a.w;
	}
};
struct bian{
	int to;
	ll w;
};
vector <node> g[1010];
vector <bian> e[1010];
int dis[1010];
priority_queue <edge> q;

void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(node x:g[i])
		{
			for(node y:g[i])
			{
				if(x.a==y.a&&x.t==y.t)
					continue;
				e[x.a].push_back({y.a,x.t+y.t});
			}
		}
	}
	while(Q--)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		for(int i=1;i<=m;i++)
		{
			dis[i]=1e9;
		}
		dis[s]=0;
		while(!q.empty()) q.pop();
		q.push({s,1ll*0});
		while(!q.empty())
		{
			edge cur=q.top();
			int u=cur.u;
			q.pop();
			for(bian v:e[u])
			{
				int to=v.to;
				ll costt=v.w;
				if(dis[u]+costt<dis[to])
				{
					dis[to]=dis[u]+costt;
					q.push({to,dis[to]});
				}
			}
		}
		printf("%lld\n",dis[t]+w[s]+w[t]);
	}
}

int main()
{
//	fre
//	freopen("C:\\Users\\Administrator\\Desktop\\subway4.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
//	bool pfa=true;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
//		if(k>2) pfa=false;
		for(int j=1;j<=k;j++)
		{
			int a;ll t;
			scanf("%d %lld",&a,&t);
			g[i].push_back({a,t});
		}
	}
	solve();
//	if(pfa) dopfa();
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
