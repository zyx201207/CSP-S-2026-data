//GZ-S00322×ñÒåËÄÖĞÕÔÕñÓî
#include<bits/stdc++.h>
#define M 1001
#define Q 100001
#define PII pair<int,int>
using namespace std;
struct node
{
	int nxt,to,w,id;
}edge[500005];
int head[M*3];
int cnt;
int c,n,m,d,q;
int w[M];
int k[505];
int a[505][M*3];
int t[505][M*3];
int x[Q];
int y[Q];
int dis[M*3];
bool vis[M][505];
int idd[M];
void add(int u,int v,int w,int idx)
{
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].id=idx;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dijkstra(int st)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(false));
	memset(idd,0,sizeof(idd));
	dis[st]=0;	
	q.push(make_pair(dis[st],st));
	while(!q.empty())
	{
		PII tmp=q.top();
		q.pop();
		int u=tmp.second;
		if(vis[u][idd[u]])
			continue;
		vis[u][idd[u]]=true;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			int w=edge[i].w;
			int ixx=edge[i].id;
			if(idd[u]!=ixx&&u>2*m&&v>2*m)
				continue;
			if((idd[u]==0&&ixx!=0)||(idd[u]!=0&&ixx==0)||(idd[u]==ixx))
			{
				if(dis[v]>=dis[u]+w)
				{
					dis[v]=dis[u]+w;
					idd[v]=ixx;
					if(!vis[v][idd[v]])
						q.push(make_pair(dis[v],v));
				}
			}
			else if((idd[u]!=ixx)&&(u>m&&u<2*m)&&(v>2*m))
			{
				if(dis[v]>=dis[u]+w)
				{
					dis[v]=dis[u]+w;
					idd[v]=ixx;
					if(!vis[v][idd[v]])
						q.push(make_pair(dis[v],v));
				}
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
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=m;i++)
	{
		add(i,i+m,w[i],0);
		add(i+m,i,w[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			int v=a[i][j];
			add(v+m,v+m+m,t[i][j],i);
			add(v+m+m,v+m,t[i][j],i);
			if(j!=1)
			{
				add(a[i][1]+m+m,a[i][j]+m+m,0,i);
				add(a[i][j]+m+m,a[i][1]+m+m,0,i);
			}
		}
	}
	for(int j=1;j<=q;j++)
	{	
		dijkstra(x[j]);
		cout<<dis[y[j]]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
