#include <bits/stdc++.h>
#define ll long long
#define endl putchar(10)
#define spc putchar(32)
using namespace std;

ll read()
{
	ll x=0,f=1; char c=getchar(); while(c<48 || c>57)
	f=(c=='-'?-1:1), c=getchar(); while(c>47 && c<58)
	x=(x<<1)+(x<<3)+c-48, c=getchar(); return x*f;
}

void write(ll x)
{
	ll st[41],tp=0; if(x<0) putchar('-'), x=-x; do st[tp++]=x%10,
	x/=10; while(x); while(tp) putchar(st[--tp]+48);
}

ll t,n,k,u,v,lst[11],cnt,p[11],bz[11],f[11][11],ans;
struct edge {ll u,v;} e[21];
void add(ll u, ll v) {e[++cnt]={lst[u],v}; lst[u]=cnt;}

void dg(ll x, ll y)
{
	bz[x]=1; for(int i=lst[x]; i; i=e[i].u)
	{if(e[i].v!=y && p[e[i].v]) dg(e[i].v,x);}
}

void dfs(ll x, ll y)
{
	if(x>n)
	{
		if(y!=k) return; ll cnt=0,res,mx=0;
		for(int i=1; i<=n; ++i) bz[i]=0;
		for(int i=1; i<=n; ++i) {if(!bz[i] && p[i])
		++cnt, dg(i,0);} if(cnt>2) return;
		for(int i=1; i<=n; ++i) {if(p[i]) continue; res=1e18;
		for(int j=1; j<=n; ++j) {if(p[j]) res=min(res,f[i][j]);}
		mx=max(mx,res);} ans=min(ans,mx); return;
	}
	
	dfs(x+1,y); p[x]=1; dfs(x+1,y+1); p[x]=0;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); read(); t=read();
	
	while(t--)
	{
		n=read(); k=read(); ans=1e18; for(int i=1; i<=n; ++i)
		{for(int j=1; j<=n; ++j) {if(i!=j) f[i][j]=1e18;}}
		for(int i=1; i<n; ++i) u=read(), v=read(),
		add(u,v), add(v,u), f[u][v]=1, f[v][u]=1;
		
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=n; ++j)
			{
				if(i==j) continue; for(int k=1; k<=n; ++k)
				{if(i!=k && j!=k) f[j][k]=min(f[j][k],
				f[j][i]+f[i][k]), f[k][j]=f[j][k];}
			}
		}
		
		dfs(1,0); write(ans); endl;
		cnt=0; for(int i=1; i<=n; ++i) lst[i]=0;
	}

	return 0;
}
