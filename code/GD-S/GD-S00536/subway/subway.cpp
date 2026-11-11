//code by ElderFour
//problem:
#include<bits/stdc++.h>
using namespace std;
const long long N=510,INF=1e18,M=500010;
long long dis[N][N],head[N],cnt,c,n,m,d,Q,MM,k[M];
long long rail[M][22],w[M],s[M][22],answer=INF,sum;
bool vis[N][N];
struct Edge
{
	long long nxt;
	long long v;
	long long w;
}edge[N*N*2];
void add_edge(long long u,long long v,long long w)
{
	cnt++;
	edge[cnt].nxt=head[u];
	edge[cnt].v=v;
	edge[cnt].w=w;
	head[u]=cnt;
	return;
}
struct Node
{
	long long no,s;
	Node(long long x,long long y){no=x,s=y;}
	bool operator < (const Node &other)const
	{
		return s>other.s;
	}
};
priority_queue<Node>q;
void dij(long long start)
{
	for(int i=1;i<=n;i++)dis[start][i]=INF;
	dis[start][start]=0;
	while(!q.empty())q.pop();
	q.push(Node(start,0));
	while(!q.empty())
	{
		Node f=q.top();
		q.pop();
		if(vis[start][f.no])continue;
		vis[start][f.no]=1;
		for(int i=head[f.no];i;i=edge[i].nxt)
		{
			long long v=edge[i].v;
			if(dis[start][v]>dis[start][f.no]+edge[i].w)
			{
				dis[start][v]=dis[start][f.no]+edge[i].w;
				if(!vis[start][v])q.push(Node(v,dis[start][v]));
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>MM;
		for(int j=1;j<=MM;j++)
		{
			long long x,y;
			cin>>x>>y;
			k[x]++;
			rail[x][k[x]]=i,s[x][k[x]]=y;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k[i];j++)
		{
			for(int K=j+1;K<=k[i];K++)
			{
				add_edge(rail[i][j],rail[i][K],s[i][j]+s[i][K]);
				add_edge(rail[i][K],rail[i][j],s[i][j]+s[i][K]);
			}
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	while(Q--)
	{
		long long x,y;
		cin>>x>>y;
		answer=INF;
		for(int i=1;i<=k[x];i++)
		{
			for(int j=1;j<=k[y];j++)
			{
//				cout<<rail[x][i]<<' '<<rail[y][j]<<':';
				sum=w[x]+w[y];
				sum+=s[x][i]+s[y][j];
				sum+=dis[rail[x][i]][rail[y][j]];
				answer=min(answer,sum);
//				cout<<sum<<'\n';
			}
		}
		cout<<answer<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
