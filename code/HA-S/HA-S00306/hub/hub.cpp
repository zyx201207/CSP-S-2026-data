#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar((x%10)^48);
}
const int N=1005,M=1005;
int n,k;
struct edge
{
	int to,nxt;
}g[M<<1];
int h[N],dis[M][M],cnt;
void add_edge(int a,int b)
{
	g[++cnt]={b,h[a]};
	h[a]=cnt;
}
bitset<N> vis;
void dfs(int u,int f,int s)
{
	vis[u]=1;
	for(int i=h[u];i;i=g[i].nxt)
	{
		int v=g[i].to;
		if(vis[v]||!((1<<v-1)&s)) continue;
		dfs(v,u,s);
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--)
	{
		if(c<=3)
		{
			n=read(),k=read();
			cnt=0;
			memset(h,0,sizeof(h));
			memset(dis,0x3f,sizeof(dis));
			for(int i=1;i<n;i++)
			{
				int u=read(),v=read();
				add_edge(u,v);
				add_edge(v,u);
				dis[u][v]=dis[v][u]=1;
				dis[i][i]=dis[i+1][i+1]=0;
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
			int ans=0x7fffffff;
			for(int s=0;s<(1<<n);s++)
			{
				if(__builtin_popcount(s)!=k) continue;
				vis.reset();
				int tmp=0;
				for(int i=1;i<=n;i++)
				{
					if(((1<<i-1)&s)&&!vis[i]) 
					{
						tmp++;
						dfs(i,-1,s);
					}
				}
				if(tmp>2) continue;
				int radi=0;
				for(int i=1;i<=n;i++)
				{
					int d=0x7fffffff;
					if((1<<i-1)&s) radi=max(radi,0ll);
					for(int j=1;j<=n;j++)
					{
						if((1<<j-1)&s) d=min(d,dis[i][j]);
					}
					radi=max(radi,d);
				}
				
				ans=min(ans,radi);
			}
			write(ans);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

