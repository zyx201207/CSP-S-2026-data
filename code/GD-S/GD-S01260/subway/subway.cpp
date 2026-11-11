#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5.5e5;
int g[1011][1011],dis[N+11],x[N+11],t[N+11],k[N*2+11],w[N+11],to[N*2+11],nxt[N*2+11],head[N*2+11],cnt;
bool pd[N*2+11];
inline void add(const int &u,const int &v,const int &w1){++cnt,to[cnt]=v,k[cnt]=w1,nxt[cnt]=head[u],head[u]=cnt;}
inline int read()
{
	int f=0,k=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')k=-1;
		c=getchar();
	}
	while(isdigit(c))
		f=f*10+c-'0',c=getchar();
	return k*f;
}
void print(int ans)
{
	if(!ans)return;
	print(ans/10);
	putchar('0'+ans%10);
}
inline int min(int x,int y){return x<y?x:y;}
typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > p;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	if(c<=11)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=LLONG_MAX;
		while(m--)
		{
			int k;
			k=read();
			for(int i=1;i<=k;i++)
			{
				x[i]=read(),t[i]=read();
				for(int j=1;j<i;j++)
				{
					g[x[j]][x[i]]=min(g[x[j]][x[i]],t[i]+t[j]);
					g[x[i]][x[j]]=min(g[x[i]][x[j]],t[i]+t[j]);
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(g[i][k]!=LLONG_MAX&&g[k][j]!=LLONG_MAX)
						g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		while(q--)
		{
			int x,y;
			x=read(),y=read();
			print(g[x][y]+w[x]+w[y]),putchar('\n');
		}
	}
	else
	{
		for(int i=1;i<=n+m;i++)
			head[i]=0;
		int um=m;
		cnt=0;
		while(m--)
		{
			int k;
			k=read();
			for(int i=1;i<=k;i++)
			{
				x[i]=read(),t[i]=read();
				add(x[i],n+m,t[i]);
				add(n+m,x[i],t[i]);
			}
		}
		m=um;
		while(q--)
		{
			int x,y;
			x=read(),y=read();
			for(int i=1;i<=n+m;i++)
				pd[i]=0;
			for(int i=1;i<=n+m;i++)
				dis[i]=LLONG_MAX;
			dis[x]=0;
			p.push({0,x});
			while(p.size())
			{
//			printf("%lld %lld\n",x,y);
				int u=p.top().second;
//				printf("%lld ",u);
				p.pop();
				if(u==y)break;
				if(pd[u])
					continue;
				pd[u]=1;
				for(int i=head[u];i;i=nxt[i])
				{
					int v=to[i];
					if(dis[u]+k[i]<dis[v])
					{
						dis[v]=dis[u]+k[i];
						p.push({dis[v],v});
					}
				}
			}
			while(p.size())p.pop();
			print(dis[y]+w[x]+w[y]),putchar('\n');
		}
	}
	return 0;
}
