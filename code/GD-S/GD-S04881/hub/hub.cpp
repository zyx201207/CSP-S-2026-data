#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif

inline ll read()
{
	ll x=0,f=1;
	char ch=' ';
	while (!isdigit(ch))
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void prt(ll x)
{
	if (x>0)
	{
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	else if (x==0) putchar('0');
	else
	{
		putchar('-');
		x=-x;
		int stac[20],top=0;
		while (x)
		{
			stac[top++]=x%10;
			x/=10;
		}
		while (top--)
		{
			putchar((char)(stac[top]^48));
		}
	}
	return;
}

const int maxn=2e6+10;

int C,T,n,k,t,ans,x,y;
int head[maxn],tot=1,nxt[maxn<<1],to[maxn<<1];
int dep[maxn],f[maxn][20],col[maxn];

inline void init()
{
	for (int i=1;i<=n;i++)
	{
		head[i]=0;
	}
	for (int i=2;i<=tot;i++)
	{
		nxt[i]=to[i]=0;
	}
	tot=1;
	return;
}

inline void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x],head[x]=tot;
}

inline void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for (int i=1;i<=t;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for (int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if (y==fa) continue;
		dfs1(y,x);
	}
}

inline int dis(int u,int v)
{
	int x=u,y=v;
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=t;i>=0;i--)
	{
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
		if (x==y) return dep[u]+dep[v]-(dep[x]<<1);
	}
	for (int i=t;i>=0;i--)
	{
		if (f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return dep[u]+dep[v]-(dep[f[x][0]]<<1);
}

inline void dfs2(int x,int fa,int S,int CO)
{
	col[x]=CO;
	for (int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if (y==fa) continue;
		if (S&(1<<(y-1))) dfs2(y,x,S,CO);
	}
}

inline void solve()
{
	init();
	n=read(),k=read();
	t=log(n)/log(2)+1;
	for (int i=1;i<n;i++)
	{
		x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	ans=n+1;
	for (int S=1;S<(1<<n);S++)
	{
		if (__builtin_popcount(S)!=k) continue;
		int CO=0,R=0;
		vector<int>inS;
		memset(col,0,sizeof(col));
		for (int x=1;x<=n;x++)
		{
			if (S&(1<<(x-1)))
			{
				inS.push_back(x);
				if (!col[x])
				{
					dfs2(x,0,S,++CO);
				}
			}
		}
		if (CO>2) continue;
		for (int x=1;x<=n;x++)
		{
			if (S&(1<<(x-1))) continue;
			int Dis=n+1;
			for (auto y:inS)
			{
				Dis=min(Dis,dis(x,y));
			}
			R=max(R,Dis);
		}
		ans=min(ans,R);
	}
	prt(ans),putchar('\n');
	return;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	C=read(),T=read();
	while (T--) solve();
	
	return 0;
}
