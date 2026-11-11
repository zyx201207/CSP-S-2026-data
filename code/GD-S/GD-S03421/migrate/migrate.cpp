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

ll t,n,k,u[2500001],v[2500001],x[5001],lst[5001],cnt,q[5001],
dis[5001],d[5001],f[5001][5001],tt[5001],bz[5001],ans;
struct edge {ll u,v;} e[2500001];
void add(ll u, ll v) {e[++cnt]={lst[u],v}; lst[u]=cnt;}

void bfs(ll x)
{
	for(int i=1; i<=n; ++i) dis[i]=-1;
	dis[x]=0; q[1]=x; ll head=0,tail=1;
	
	while(head<tail)
	{
		++head; for(int i=lst[q[head]]; i; i=e[i].u)
		{if(dis[e[i].v]<0) q[++tail]=e[i].v,
		dis[e[i].v]=dis[q[head]]+1;}
	}
}

void calc(ll x)
{
	for(int i=1; i<=n; ++i) d[i]=0, bz[i]=0;
	d[x]=1; bz[x]=1; q[1]=x; ll head=0,tail=1;

	while(head<tail)
	{
		++head; for(int i=1; i<=tt[q[head]]; ++i)
		{ll v=f[q[head]][i]; d[v]+=d[q[head]];
		if(!bz[v]) q[++tail]=v, bz[v]=1;}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); read(); t=read();
	
	while(t--)
	{
		n=read(); k=read(); ans=0;
		for(int i=1; i<=n; ++i) x[i]=read();
		
		for(int i=1; i<n; ++i)
		{
			for(int j=i+1; j<=n; ++j)
			{
				if(x[j]-x[i]>k) break;
				add(i,j); u[cnt]=i; v[cnt]=j;
				add(j,i); u[cnt]=j; v[cnt]=i;
			}
		}
		
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=n; ++j) tt[j]=0;
			bfs(i); for(int j=1; j<=cnt; ++j)
			{if(dis[u[j]]+1==dis[v[j]]) f[u[j]][++tt[u[j]]]=v[j];}
			calc(i); for(int j=i+1; j<=n; ++j) ans+=d[j]==2;
		}
		
		write(ans); endl; cnt=0; for(int i=1; i<=n; ++i) lst[i]=0;
	}

	return 0;
}
