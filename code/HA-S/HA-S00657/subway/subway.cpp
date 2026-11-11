#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
typedef long long ll;

typedef struct edge
{
	int to,w,nxt;
}edge;
edge e[N<<1];

int head[N],cnt;
void addedge(int u,int v,int w)
{
	e[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
}

int c,n,m,d,q,w[N];
ll dis[N],ans[1005][1005];
bool vis[N];
typedef struct node
{
	int num;
	ll d;
	bool operator<(const node &nd) const
	{
		return d>nd.d;
	}
}node;
priority_queue<node> qu;

void init()
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
}

void djk(int x)
{
	init();
	dis[x]=0;
	qu.push((node){x,dis[x]});
	while(!qu.empty())
	{
		node nf=qu.top();
		qu.pop();
		int u=nf.num;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				qu.push((node){v,dis[v]});
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		for(int j=1;j<=t;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a,m+i,b);
			addedge(m+i,a,b);
		}
	}
	if(q>2000)
	{
		for(int i=1;i<=m;i++)
		{
			djk(i);
			for(int j=1;j<=m;j++)
				ans[i][j]=dis[j];
		}
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",ans[x][y]+w[x]+w[y]);
		}
	}
	else
	{
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			djk(x);
			printf("%lld\n",dis[y]+w[x]+w[y]);
		}
	}
	return 0;
}
