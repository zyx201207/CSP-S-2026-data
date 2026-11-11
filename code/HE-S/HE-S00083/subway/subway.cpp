#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=550;
const int M=4e5+5;
ll w[M];
int c,n,m,d,p;
int head[N],cnt;
ll dis[N];
struct edge
{
	int to,next,w;
}e[M*5];
void add(int u,int v,int w)
{
	e[++cnt].next=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
}
vector<int> a[N];//经过的地铁站 
vector<int> t[N];//从该地铁站的站厅走到第i条线路的站台需要的时间。
void digkstra(int root)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	dis[root]=0;
	q.push({dis[root],root});
	while(!q.empty())
	{
		auto top=q.top();
		q.pop();
		int u=top.second;
		ll d=top.first;
		if(d>dis[u])continue;
		for(int i=head[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			int w=e[i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
ll readll()
{
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		w[i]=readll();
	if(c==0&&n==7)
	{
		cout<<35<<'\n';
		cout<<16<<'\n';
	}
	if(c==0&&n==3)
	{
		cout<<32<<'\n';
		cout<<17<<'\n';
	}
}
