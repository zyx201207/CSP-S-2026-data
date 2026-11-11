#include<bits/stdc++.h>
#define PI pair<int,int>
#define int long long
using namespace std;
const int N=510,M=5e5+1e4;
int cid,n,m,D,Q,w[M],cnt,head[M],q2[2][M];
int dis[N][N],dist[N];
map<int,int>mp[N];
bool vis[N];
struct mmm
{
	int to;
	int val;
};
vector<mmm>a[M];
struct Edge
{
	int nxt;
	int to;
	int val;
}edge[N*N*2];
priority_queue<PI,vector<PI >,greater<PI > >q;
void dij(int st)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push(make_pair(0,st));
	dist[st]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int y=edge[i].to;
			int val=edge[i].val;
			if(!vis[y]&&dist[y]>dist[x]+val)
			{
				dist[y]=dist[x]+val;
				q.push(make_pair(dist[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++) dis[st][i]=dist[i];
}
void bfs(int st)
{
	int h=1,t=1,sum=0;
	q2[0][t]=st;
	q2[1][t]=0;
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	vis[st]=1;
	dist[st]=0;
	while(h<=t)
	{
		int x=q2[0][h];
		if(x<=n) sum++;
		if(sum==n) break;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int y=edge[i].to;
			int val=edge[i].val;
			if(!vis[y])
			{
				dist[y]=dist[x]+val;
				q2[0][++t]=y;
				q2[1][t]=dist[y];
				vis[y]=1;
			}
		}
		h++;
	}
	for(int i=1;i<=n;i++) dis[st][i]=dist[i];
}
void add_edge(int x,int y,int z)
{
	edge[++cnt]={head[x],y,z};
	head[x]=cnt;
}
int read()
{
	char x=getchar();
	int sum=0,fs=1;
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') sum=sum*10+x-'0',x=getchar();
	return sum*fs;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&cid,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y,z;
		for(int j=1;j<=x;j++)
		{
			y=read(),z=read();
			mp[i][y+n]=z;
			a[i].push_back({y+n,z});
			a[y+n].push_back({i,z});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			int sum=1e18;
			for(int k=0;k<(int)a[i].size();k++)
			{
				if(mp[j].count(a[i][k].to))
				{
					//printf("dsgdsfa %lld %lld\n",a[i][k].val,mp[j][a[i][k].to]);
					sum=min(sum,a[i][k].val+mp[j][a[i][k].to]);
				}
			}
			if(sum<1e18)
			{
				//printf("%lld %lld %lld\n",i,j,sum);
				add_edge(i,j,sum);
				add_edge(j,i,sum);
			}
		}
	}
	if(cid>=12&&cid<=19) for(int i=1;i<=n;i++) bfs(i);
	else for(int i=1;i<=n;i++) dij(i);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) printf("%lld ",dis[i][j]);
//		printf("\n");
//	}
	while(Q--)
	{
		int x=read(),y=read();
		int ans=1e18;
		for(int i=0;i<(int)a[x+n].size();i++)
		{
			for(int j=0;j<(int)a[y+n].size();j++)
			{
				int xx=a[x+n][i].to;
				int yy=a[y+n][j].to;
				ans=min(ans,dis[xx][yy]+a[x+n][i].val+a[y+n][j].val);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
记录dis[i][j]表示从线路i到线路j的最小距离
考虑如何计算dis[i][j]
建图
对于点a[i][j]
将a[i][j]连向超级节点D[a[i][j]],边权为t[i][j]
将a[i][j]连向超级节点X[i],边权为0
然后对于超级节点X[i]跑最短路即可
时间复杂度O(nmlog(m))
考虑优化
将X[i]连向a[i][j],边权为t[i][j] 
*/
