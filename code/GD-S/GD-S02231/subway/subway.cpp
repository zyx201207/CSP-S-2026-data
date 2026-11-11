#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

struct node
{
	ll a,t;
	inline bool operator> (const node &other) const
	{
		return t>other.t;
	}
};

ll c,n,m,d,q,w[500005],dist[500005];
vector<node> a[505];
vector<map<ll,node> > a2[505];
bool visd[500005]; 
map<ll,set<ll> > b;

//inline ll dijkstra(ll cx,ll cy)
//{
//	dist[cx]=0;
//	priority_queue<node,vector<node>,greater<node> > cc;
//	priority_queue<ll,vector<ll>,greater<ll> > cl; 
////	for(auto &i:b[cx])
////	{
////		cc.push({i,w[cx]+a[cx][i]});
////	}
//	cc.push({cx,0});
//	for(;!cc.empty();)
//	{
//		node u=cc.top();
//		cc.pop();
//		if(visd[u.a])
//		{
//			continue;
//		}
//		visd[u.a]=true;
//		for(auto &uc:b[u.a])
//		{
//			cl.push(uc);
//		}
//		for(;!cl.empty();)
//		{
//			ll cca=cl.top();
//			cl.pop();
//			for(ll v=1;v<a[cca].size();++v)
//			{
//				if(dist[a[cca][v].a]>dist[u.a]+w[u.a]+a[cca][v].t)
//				{
//					cc.push(a[cca][v]);
//					dist[a[cca][v].a]=dist[u.a]+w[u.a]+a[cca][v].t;
//				}
//			}
//		}
//	}
//	return dist[cy]+dist[cx];
//}

int dis[6002][6002];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=m;++i)
	{
		scanf("%lld",&w[i]);
	}
	if(12<=c&&c<=19)
	{
		for(ll i=1;i<=n;++i)
		{
			ll cache;
			scanf("%lld",&cache);
//			a[i].push_back({cache,cache});
			for(ll j=1;j<=cache;++j)
			{
				ll ca,ct;
				scanf("%lld%lld",&ca,&ct);
				b[ca].insert(i);
				a[i].push_back({ca,ct});
			}
		}
		for(ll i=1;i<=m;++i)
		{
			for(ll j=1;j<=n;++j)
			{
				for(ll k=1;k<=m;++k)
				{
					if(i==k) continue;
					if(b[i].find(j)!=b[i].end()&&b[k].find(j)!=b[k].end())
					{
						dis[i][k]=2;
						dis[k][i]=2;
					}
					else
					{
						int cache=dis[j][i]+dis[i][k];
						if(cache<dis[j][k])
						{
							dis[j][k]=cache;
							dis[k][j]=cache;
						}
					}
				}
			}
		}
		for(ll i=1;i<=q;++i)
		{
			int cxx,cyx;
			scanf("%d%d",&cxx,&cyx);
//			memset(dist,0x7f,sizeof(dist));
//			memset(visd,false,sizeof(visd));
			printf("%d\n",dis[cxx][cyx]);
		}
		return 0;
	}
	for(ll i=1;i<=n;++i)
	{
		ll cache;
		scanf("%lld",&cache);
		a[i].push_back({0,0});
		for(ll j=1;j<=cache;++j)
		{
			ll ca,ct;
			scanf("%lld%lld",&ca,&ct);
			b[ca].insert(i);
			a[i].push_back({ca,ct});
			++a[i][0].a;
		}
	}
	for(ll i=1;i<=m;++i)
	{
		for(ll j=1;j<=n;++j)
		{
			for(ll k=1;k<=m;++k)
			{
				if(i==k) continue;
				if(b[i].find(j)!=b[i].end()&&b[k].find(j)!=b[k].end())
				{
					dis[i][k]=w[i]+w[k];
					dis[k][i]=w[i]+w[k];
					for(ll p=1;p<a[i].size();++p)
					{
						if(a[j][p].a==i||a[j][p].a==k)
						{
							dis[i][k]+=a[j][p].t;
							dis[k][i]+=a[j][p].t;
						}
					}
				}
				else
				{
					ll cache=dis[j][i]+dis[i][k];
					if(cache<dis[j][k])
					{
						dis[j][k]=cache;
						dis[k][j]=cache;
					}
				}
			}
		}
	}
	for(ll i=1;i<=q;++i)
	{
		ll cxx,cyx;
		scanf("%lld%lld",&cxx,&cyx);
//		memset(dist,0x7f,sizeof(dist));
//		memset(visd,false,sizeof(visd));
		printf("%lld\n",min(dis[cxx][cyx],dis[cyx][cxx]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
