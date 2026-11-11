#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2;
int c,n,m,d,p,k,dis[5001],w[N],nxt[N],to[N],len[N],head[N],cnt;
bool vis[N];
void add(int x,int y,int z)
{
	nxt[++cnt]=head[x];
	head[cnt]=x;
	to[cnt]=y;
	len[cnt]=z;
}
priority_queue<pair<int,int> >q;
void dijkstra(int s)
{
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int d=-q.top().first,x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i],z=len[i];
			if(dis[y]>dis[x]+z)
			{
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			add(i,a,t+w[a]);
		}
	}
	while(p--)
	{
		int x,y;
		cin>>x>>y;
		memset(dis,0,sizeof(dis));
		while(!q.empty())q.pop();
		dijkstra(x);
		cout<<dis[y]<<endl;
	}
	return 0;
}