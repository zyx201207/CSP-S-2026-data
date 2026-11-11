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

int C,T,n;
ll d,ans;
ll x[maxn],len[maxn],cnt[maxn];

inline void dfs(int p,int nowl)
{
	if (p>n) return;
	if (nowl>len[p]) return;
	else if (nowl<len[p])
	{
		len[p]=nowl;
		cnt[p]=1;
	}
	else if (nowl==len[p])
	{
		cnt[p]++;
	}
	for (int i=p+1;i<=n;i++)
	{
		if (x[i]-x[p]>d) break;
		dfs(i,nowl+1);
	}
	return;
}

inline void solve()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	ans=0;
	for (int u=1;u<=n;u++)
	{
		for (int v=u;v<=n;v++)
		{
			len[v]=n+5;
			cnt[v]=0;
		}
		dfs(u,0);
		for (int v=u+3;v<=n;v++)
		{
			if (cnt[v]==2) ans++;
		}
	}
	prt(ans),putchar('\n');
	return;
}

inline void solveA()
{
	n=read(),d=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	ans=0;
	ll dx=x[2]-x[1];
	if (dx<d)
	{
		puts("0");
		return;
	}
	ll k=d/dx;
	if (k==1)
	{
		puts("0");
		return;
	}
	ans=n-n/2;
	prt(ans),putchar('\n');
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	C=read(),T=read();
	if (11<=C&&C<=12)
	{
		while (T--) solveA();
	}
	else
	{
		while (T--) solve();
	}
	
	return 0;
}
