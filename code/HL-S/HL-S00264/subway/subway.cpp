#include<bits/stdc++.h>
using namespace std;

#define pii pair<long long,int>

const int N=505;
const int M=5e5+5;
int c,n,m,d,q;
long long w[M];
int k;
int x,y;
int e[M<<1],nxt[M<<1],h[N+M];
long long ww[M<<1];
bitset<N+M>vis;
int id;

void add(int x,int y,int z)
{
	e[++id]=y;
	nxt[id]=h[x];
	h[x]=id;
	ww[id]=z;
}

long long dij(int s,int t)
{
	vis&=0;
	priority_queue<pii,vector<pii>,greater<pii> >Q;
	Q.push({0,s});
	while(Q.size())
	{
		long long dis=Q.top().first;
		int u=Q.top().second;
		Q.pop();
		if(u==t) return dis;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i])
		{
			int v=e[i];
			if(!vis[v]) Q.push({dis+ww[i],v});
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k==2)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			add(x1,x2,y1+y2);
			add(x2,x1,y1+y2);
		}
		else for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&x,&y);
			add(i+m,x,y);
			add(x,i+m,y);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%lld\n",dij(x,y)+w[x]+w[y]);
	}
	return 0;
}
