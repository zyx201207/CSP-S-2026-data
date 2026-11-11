#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1.2e6+9,inf=1e18;
ll id,n,m,d,Q;
ll a[N];
//1~m:站点
//m+1~2m:站厅
//2m+1~2m+n:线路编号
//n=500,m=5e5,∑k=5e5
ll idx,head[N];
struct edge
{
	ll to,next,w;
}e[N<<1];
void addedge(ll u,ll v,ll w)
{
	idx++;
	e[idx].to=v;
	e[idx].next=head[u];
	e[idx].w=w;
	head[u]=idx;
}
struct node
{
	ll d,id;
};
bool operator< (node x,node y)
{
	return x.d>y.d;
}
ll dis[N],vis[N];
ll ANS[1002][1002];
priority_queue<node>q;
void dijkstra(ll s)
{
	for(int i=1;i<=m+n;i++)
	{
		dis[i]=inf;
		vis[i]=0; 
	}
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty())
	{
		node tem=q.top();
		q.pop();
		ll u=tem.id;
		if(vis[u])continue;
		for(int i=head[u];i;i=e[i].next)
		{
			ll v=e[i].to,w=e[i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push((node){dis[v],v});
			}
		}
	}
}
ll op[N],cb[3][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&id,&n,&m,&d,&Q);
	bool sub20=(n<=2);
	for(int i=1;i<=m;i++)
	{
		ll w;
		scanf("%lld",&w);
		a[i]=w;
	}
	for(int i=1;i<=n;i++)
	{
		ll Ln=m+i;
		ll o,v,w;
		scanf("%lld",&o);
		while(o--)
		{
			scanf("%lld%lld",&v,&w);
			if(sub20)
			{
				op[v]+=i;
				cb[i][v]+=w;
			}
			addedge(Ln,v,w);
			addedge(v,Ln,w);
		}
	}
	
	if(m<=1000)//sub 9~11
	{
		for(int i=1;i<=m;i++)
		{
			dijkstra(i);
			for(int j=1;j<=m;j++)
			ANS[i][j]=dis[j];
		}
		while(Q--)
		{
			ll u,v;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",a[u]+ANS[u][v]+a[v]);
		}
		return 0;
	}
	
	if(m>=1e5&&n==2)//sub20,21
	{
		ll mich=inf;//最小换乘成本 
		for(int i=1;i<=m;i++)//换乘站 
		if(op[i]==3)mich=min(mich,cb[1][i]+cb[2][i]);
		while(Q--)
		{
			ll u,v,ret=inf;
			scanf("%lld%lld",&u,&v);
			if(op[u]==op[v]&&op[u]<3)
			{
				ret=a[u]+cb[op[u]][u]+cb[op[v]][v]+a[v];
			}
			if(op[u]==op[v]&&op[v]==3)
			{
				ret=min({	a[u]+cb[1][u]+cb[1][v]+a[v],
							a[u]+cb[2][u]+cb[2][v]+a[v],
							a[u]+cb[1][u]+mich+cb[2][v]+a[v],
							a[u]+cb[2][u]+mich+cb[1][v]+a[v]});
			}
			if(op[u]==1&&op[v]==2||op[u]==2&&op[v]==1)
			{
				ret=a[u]+cb[op[u]][u]+mich+cb[op[v]][v]+a[v];
			}
			if(op[u]==3&&op[v]<3)
			{
				ret=min({	a[u]+cb[op[v]][u]+cb[op[v]][v]+a[v],
							a[u]+cb[3-op[v]][u]+mich+cb[op[v]][v]+a[v]});
			}
			if(op[u]<3&&op[v]==3)
			{
				ret=min({	a[u]+cb[op[u]][u]+cb[op[u]][v]+a[v],
							a[u]+cb[op[u]][u]+mich+cb[3-op[u]][v]+a[v]});
			}
			printf("%lld\n",ret);
		}
		return 0;
	}
	/*
	if(d<=2)//sub22,23
	{
		
	}
	*/
	while(Q--)//sub1~8,12~15
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		dijkstra(u);
		printf("%lld\n",a[u]+dis[v]+a[v]);
	}
	return 0;
}
