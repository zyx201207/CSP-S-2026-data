#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505,MAXD=25,MAXM=1005;
struct Edge
{
	int x,y,w;
};
struct Que
{
	int x,y,dis;
	bool operator<(const Que &a)const
	{
		return dis>a.dis;
	}
};
vector<Edge> e[MAXM][MAXN];
int c,n,m,d,qq;
int w[MAXM],dis[MAXM][MAXN],vis[MAXM][MAXN];
priority_queue<Que> q;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void work()
{
	int x=0,y=0;
	x=read(),y=read();
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[x][0]=0;
	q.push({x,0,0});
	while(q.size())
	{
		Que u=q.top();
		q.pop();
		if(vis[u.x][u.y])
		{
			continue;
		}
		vis[u.x][u.y]=1;
		for(auto v:e[u.x][u.y])
		{
			int vx=v.x,vy=v.y;
			if(dis[u.x][u.y]+v.w<dis[vx][vy])
			{
				dis[vx][vy]=dis[u.x][u.y]+v.w;
				q.push({vx,vy,dis[vx][vy]});
			}
		}
	}
	printf("%lld\n",dis[y][0]+w[x]+w[y]);
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),qq=read();
	for(int i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k=0,a=0,t=0,l=0;
		k=read();
		a=read(),t=read();
		e[a][0].push_back({a,i,t});
		e[a][i].push_back({a,0,t});
		l=a;
		for(int j=2;j<=k;j++)
		{
			a=read(),t=read();
			e[a][0].push_back({a,i,t});
			e[a][i].push_back({a,0,t});
			e[a][i].push_back({l,i,0});
			e[l][i].push_back({a,i,0});
			l=a;
		}
	}
	while(qq--)
	{
		work();
	}
	return 0;
}
