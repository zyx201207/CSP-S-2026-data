#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define inf_ll 0x3f3f3f3f3f3f3f3f

inline int read(void);
inline void write(int);

const int N=1e6+5;
int c,t,n,k;
vector<int> edge[15];
int f[15][15];

inline void floyd()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	
	return ;
}

int len,vis[15];

inline void dfs(int u,int fa)
{
	vis[u]=len;
	for (int v:edge[u])
	{
		if (vis[v]==0&&v!=fa) dfs(v,u);
	}
	
	return ;
}

inline bool check(int mask)
{
	len=0;
	memset(vis,0,sizeof(vis));
	
	for (int i=0;i<n;i++)
		if (((mask>>i)&1)&&!vis[i+1]) 
		{
			len++;
			dfs(i+1,0);
		}
	
	return len<=2;	
}

int ans;

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

//	freopen("hub1.in","r",stdin);
	
	c=read(),t=read();
	while (t--)
	{
		for (int i=1;i<=10;i++) edge[i].clear();
		
		n=read(),k=read();
		
		memset(f,0x3f,sizeof(f));
		for (int i=1;i<=n;i++) f[i][i]=0;
		
		for (int i=1;i<n;i++)
		{
			int u,v;
			u=read(),v=read();
			
			edge[u].emplace_back(v);
			edge[v].emplace_back(u);
			f[u][v]=min(f[u][v],1ll);
			f[v][u]=min(f[v][u],1ll);
		}
		
		floyd();
		
		ans=inf_ll;
		for (int mask=0;mask<(1ll<<n);mask++)
		{
			if (__builtin_popcount(mask)!=k||!check(mask)) continue;
			
			vector<int> d(n+5,inf_ll);
			for (int i=1;i<=n;i++)
			{
				if ((mask>>(i-1))&1) 
				{
					d[i]=0;
					continue;
				}
				
				for (int j=0;j<n;j++)
					if ((mask>>j)&1) d[i]=min(d[i],f[i][j+1]);
			}
			
			int maxn=0;
			for (int i=1;i<=n;i++) maxn=max(maxn,d[i]);
			
			ans=min(ans,maxn);
		}
		
		write(ans),putchar('\n');
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
