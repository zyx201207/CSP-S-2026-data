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
const int N=1005,M=500005,D=25;
struct edge
{
	int to,nxt,val;
}g[M<<2];
int h[N*D];
void add_edge(int a,int b,int c)
{
	static int cnt=0;
	g[++cnt]={b,h[a],c};
	h[a]=cnt;
}
int dis[N*D];
bitset<N*D> vis;
void dijkstra(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vis.reset();
	memset(dis,0x3f,sizeof(dis));
	q.push({0,s});
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=g[i].nxt)
		{
			int v=g[i].to,w=g[i].val;
			if(!vis[v]&&dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int n,m,d,q,w[N],k[N];
vector<int> sta[N],a[N],t[N];
inline int get(int u,int x){return u+x*m;}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)
		{
			int x=read(),y=read();
			a[i].push_back(x);
			t[i].push_back(y);
			sta[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k[i];j++)
		{
			int tmp=lower_bound(sta[a[i][j]].begin(),sta[a[i][j]].end(),i)-sta[a[i][j]].begin();
			add_edge(a[i][j],get(a[i][j],tmp+1),t[i][j]);
			add_edge(get(a[i][j],tmp+1),a[i][j],t[i][j]);
			if(j==0) continue;
			int lst=lower_bound(sta[a[i][j-1]].begin(),sta[a[i][j-1]].end(),i)-sta[a[i][j-1]].begin();
			add_edge(get(a[i][j],tmp+1),get(a[i][j-1],lst+1),0);
			add_edge(get(a[i][j-1],lst+1),get(a[i][j],tmp+1),0);
		}
	}
	while(q--)
	{
		int x=read(),y=read();
		dijkstra(x);
		write(dis[y]+w[x]+w[y]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
