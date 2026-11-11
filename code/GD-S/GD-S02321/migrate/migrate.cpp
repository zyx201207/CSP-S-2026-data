#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>

inline int read(void);
inline void write(int);

const int N=2e6+5;
int c,t,n=0,d,x[N];

vector<int> edge[305];

struct data
{
	int x,dis;
	bool operator<(const data& r) const
	{
		return dis>r.dis;
	}
};

int dis[305],cnt[305];
bitset<305> vis;

inline void dijkstra(int s)
{
	priority_queue<data> pq;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	vis.reset();
	
	pq.push({s,0});
	dis[s]=0;
	cnt[s]=1;
	
	while (!pq.empty())
	{
		int u=pq.top().x;pq.pop();
		
		if (vis[u]) continue;
		vis[u]=1;
		
		for (int v:edge[u])
		{
			if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				pq.push({v,dis[v]});
			}
			else if (dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
	
	return ;
}

inline void solve1()
{
	for (int i=0;i<=300;i++) edge[i].clear();
	
	for (int u=1;u<=n;u++)
		for (int v=u+1;v<=n;v++)
		{
			int w=x[v]-x[u];
			if (w>d) break;
			
			edge[u].emplace_back(v);
			edge[v].emplace_back(u);
		}
	
	int ans=0;
	for (int i=1;i<=n;i++)
	{
//		spfa(i);
		dijkstra(i);
		
		for (int j=i+1;j<=n;j++)
			if (cnt[j]==2) ans++;
	}
	
	write(ans),putchar('\n');
	return ;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

//	freopen("migrate3.in","r",stdin);
	
	c=read(),t=read();
	while (t--)
	{
		for (int i=1;i<=n;i++) x[i]=0;
		
		n=read(),d=read();
		for (int i=1;i<=n;i++) x[i]=read();
		
//		if (0<=c&&c<=6) 
//		{
			solve1();
			continue;
//		}
	}
	return 0;
}



inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	
	return x*f;
}

inline void write(int x)
{
	if (x<0)
	{
		x=-x;
		putchar('-');
	}
	if (x>9) write(x/10);
	putchar(x%10^48);
	
	return ;
}
