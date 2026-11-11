#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
const long long INF=1e18;
struct node
{
	int id;
	long long d;
	bool operator < (const node &h) const
	{
		return d>h.d;
	}
};
int c,n,m,d,f,x,y;
bool vis[MAX];
int head[MAX],cur,tot;
int to[MAX*4],nxt[MAX*4],k,qw[MAX],a[MAX],t[MAX];
long long dis[MAX],W[MAX*4];
void add(int u,int v,long long w)
{
	to[++tot]=v;
	W[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
priority_queue<node>q;
void djs(int s)
{
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		cur=q.top().id;
		q.pop();
		if(vis[cur])continue;
		vis[cur]=1;
		for(int i=head[cur],v;i;i=nxt[i])
		{
			v=to[i];
			if(!vis[v]&&dis[v]>dis[cur]+W[i])
			{
				dis[v]=dis[cur]+W[i];
				q.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>f;
	for(int i=1;i<=m;i++)cin>>qw[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int q=j+1;q<=k;q++)
			{
				add(a[j],a[q],t[j]+t[q]);
				add(a[q],a[j],t[j]+t[q]);
			}
		}
	}
	for(int i=1;i<=m;i++)dis[i]=INF;
	for(int i=1;i<=f;i++)
	{
		cin>>x>>y;
		djs(x);
		cout<<dis[y]+qw[x]+qw[y]<<endl;
		for(int j=1;j<=m;j++)
		{
			dis[j]=INF;
			vis[j]=0;
		}
	}
	return 0;
}
