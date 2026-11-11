#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge
{
	int to,w;
	bool operator <(const Edge &b)const
	{
		return w>b.w;
	}
};
vector<Edge> g[10500005];
int n,m,d,c,q,w[500005],dis[10500005];
bool vis[10500005];
priority_queue<Edge> pq;
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	pq.empty(); 
	pq.push({s,0});
	dis[s]=0;
	while(!pq.empty())
	{
		Edge tmp=pq.top();
		pq.pop();
		vis[tmp.to]=1;
		for(auto i:g[tmp.to])
		{
			if(!vis[i.to])
			{
				dis[i.to]=min(dis[i.to],dis[tmp.to]+i.w);
				pq.push({i.to,dis[i.w]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%lld",&k);
		vector<int> a(k+1);
		for(int j=1;j<=k;j++)
		{
			int t;
			scanf("%lld%lld",&a[j],&t);
			g[a[j]].push_back({a[j]+i*d,t});
			g[a[j]+i*d].push_back({a[j],t});
		}
		for(int j=2;j<=k;j++)
		{
			g[a[j-1]+i*d].push_back({a[j]+i*d,0});
			g[a[j]+i*d].push_back({a[j-1]+i*d,0});
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		dij(x);
		printf("%lld\n",w[x]+w[y]+dis[y]);
	}
	return 0;
}

/*

只会写T1T2，写完了，很闲啊（为什么Win10没有扫雷啊）

想起了去年HE写#include<bits\stdc++.h>的那位

HE有人写迷惑行为大赏吗？我想上榜

maybe 75+12+0+0=87pts 二等吧

饿了

*/
