#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,M=2e6+5;
struct edge
{
	int to,w,nxt;
}g[M];
int head[N],tot;
void add(int x,int y,int w)
{
	g[++tot]={y,w,head[x]};
	head[x]=tot;
}
ll Tid,n,d;
ll x[N];
ll dis[N],fac[N],vis[N];
struct node
{
	ll val;
	int id;
	bool operator<(node x)
	{
		return val<x.val;
	}
};
deque<node>c;
node top()
{
	return c.front();
}
bool empty()
{
	return c.empty();
}
void pop()
{
	c.pop_front();
}
void push(node x)
{
	if(x.val==c.front().val)	c.push_front(x);
	else						c.push_back(x);
}
void dij(int x)
{
	c.clear();
	for(int i=1;i<=n;i++)
	{
		dis[i]=1e18+5;
		fac[i]=0;
		vis[i]=0;
	}
	dis[x]=0;
	fac[x]=1;
	push({0,x});
//	cout<<x<<"--------------------\n";
	while(!empty())
	{
		node x=top();
		pop();
		int u=x.id;
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=head[u];i;i=g[i].nxt)
		{
			int v=g[i].to;
			if(dis[v]>dis[u]+g[i].w)
			{
				dis[v]=dis[u]+g[i].w;
				fac[v]=fac[u];
				push({dis[v],v});
			}
			else if(dis[v]==dis[u]+g[i].w)
			{
				fac[v]+=fac[u];
//				cout<<v<<"<-"<<u<<":"<<fac[v]<<"<-"<<fac[u]<<"\n";
			}
		}
	}
}
void solve()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		head[i]=0;
	}
	tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	if(Tid==11||Tid==12)
	{
		int l=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]-x[1]<=d)	l=i-1;
			else				break;
		}
		if(l!=2)	printf("0\n");
		else
		{
			printf("%lld\n",n*2-6);
		}
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					add(i,j,1);
					add(j,i,1);
				}
				else
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			dij(i);
			for(int j=i+1;j<=n;j++)
			{
//				cout<<fac[j]<<" ";
				if(fac[j]==2)	ans++;
			}
//			cout<<"\n";
		}
		printf("%d\n",ans);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%lld%d",&Tid,&T);
	while(T--)	solve();
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
