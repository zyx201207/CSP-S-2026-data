#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5,Q=1e5+5;
struct edge
{
	int to,w,nxt;
}g[(N+M)*2];
int head[N+M],tot;
void add(int x,int y,int w)
{
	g[++tot]={y,w,head[x]};
	head[x]=tot;
}
int Tid,n,m,d,q;				//!!!!!!!!!!!!!m才是点数
int a[N];
int l[N],ds[N],idtot;
ll dis[N+M];
bool vis[N+M];
int ques[Q][2];
ll ans[Q];
struct node
{
	ll val;
	int id;
	bool operator<(node x)
	{
		return val<x.val;
	}
};
node c[N+M];
int len;
void up(int x)
{
	while(x>1&&c[x]<c[x/2])
	{
		swap(c[x],c[x/2]);
		x/=2;
	}
}
void down(int x)
{
	while((x*2<=len&&c[x*2]<c[x])||(x*2+1<=len&&c[x*2+1]<c[x]))
	{
		int y=x*2;
		if(y+1<=len&&c[y+1]<c[y])
		{
			y++;
		}
		swap(c[x],c[y]);
		x=y;
	}
}
node top()
{
	return c[1];
}
bool empty()
{
	return len==0;
}
void pop()
{
	swap(c[1],c[len]);
	len--;
	down(1);
}
void push(node x)
{
	c[++len]=x;
	up(len);
}
void dij(int x)
{
	len=0;
	for(int i=1;i<=idtot;i++)
	{
		dis[i]=1e18+5;
		vis[i]=0;
	}
	dis[m+x]=0;
	push({0,m+x});
	while(len)
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
				push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&Tid);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)	scanf("%d",&a[i]);
	idtot=m;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&l[j],&ds[j]);
		}
		++idtot;
		for(int j=1;j<=k;j++)
		{
			add(l[j],idtot,ds[j]);
			add(idtot,l[j],ds[j]);
		}
	}
//	for(int i=1;i<=idtot;i++)
//	{
//		cout<<i<<":";
//		for(int j=head[i];j;j=g[j].nxt)
//		{
//			int v=g[j].to;
//			cout<<v<<",";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&ques[i][0],&ques[i][1]);
		ans[i]=1e18+5;
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
//		for(int j=1;j<=idtot;j++)
//		{
//			cout<<dis[j]<<" ";
//		}
//		cout<<"\n";
		for(int j=1;j<=q;j++)
		{
			ans[j]=min(ans[j],dis[ques[j][0]]+dis[ques[j][1]]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		printf("%lld\n",ans[i]+a[ques[i][0]]+a[ques[i][1]]);
	}
	return 0;
}


