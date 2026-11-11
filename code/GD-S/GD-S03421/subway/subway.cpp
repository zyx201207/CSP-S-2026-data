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

ll n,m,q,k,x,y,f[501][501],w[500001],ans;
struct node {ll x,y;}; vector<node> v[500001];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(); n=read(); m=read(); read(); q=read();
	for(int i=1; i<=m; ++i) w[i]=read();
	
	for(int i=1; i<=n; ++i)
	{
		k=read(); while(k--) x=read(),
		y=read(), v[x].push_back({i,y});
		for(int j=1; j<=n; ++j) {if(i!=j) f[i][j]=1e18;}
	}
	
	for(int i=1; i<=m; ++i)
	{
		for(int j=0; j<v[i].size(); ++j)
		{
			for(int k=j+1; k<v[i].size(); ++k)
			f[v[i][j].x][v[i][k].x]=
			min(f[v[i][j].x][v[i][k].x],v[i][j].y+v[i][k].y),
			f[v[i][k].x][v[i][j].x]=f[v[i][j].x][v[i][k].x];
		}
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(i==j) continue; for(int k=1; k<=n; ++k)
			{if(i!=k && j!=k) f[j][k]=min(f[j][k],
			f[j][i]+f[i][k]), f[k][j]=f[j][k];}
		}
	}

	while(q--)
	{
		x=read(); y=read(); ans=1e18;
		
		for(int i=0; i<v[x].size(); ++i)
		{
			for(int j=0; j<v[y].size(); ++j) ans=min
			(ans,f[v[x][i].x][v[y][j].x]+v[x][i].y+v[y][j].y);
		}
		
		write(ans+w[x]+w[y]); endl;
	}

	return 0;
}
