#include<bits/stdc++.h>
typedef long long ll;
const ll N=505,M=5e5+5,inf=1e18;
using namespace std;
ll C,n,m,d,q,a,b,w[M],f[N][N],l,x,y;
struct node {
	ll b,c;
};vector<node> v[M];
ll read()
{
	ll x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x;
}
void print(ll x)
{
	if (x>9)
	{
		print(x/10);
	}
	putchar('0'+x%10);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++)
	{
		w[i]=read();
	}
	for(ll i=1;i<=n;i++)
	{
		l=read();
		for(ll j=1;j<=l;j++)
		{
			a=read(),b=read();
			v[a].push_back({i,b});
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			f[i][j]=(i!=j)*inf;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=0;j<=v[i].size()-1;j++)
		{
			for(ll k=0;k<=v[i].size()-1;k++)
			{
				if (j!=k)
				{
					f[v[i][j].b][v[i][k].b]=min(f[v[i][j].b][v[i][k].b],v[i][j].c+v[i][k].c);
				}
			}
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if (i!=j&&j!=k)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		x=read(),y=read();
		ll ans=inf;
		for(ll i=0;i<=v[x].size()-1;i++)
		{
			for(ll j=0;j<=v[y].size()-1;j++)
			{
				ans=min(ans,v[x][i].c+f[v[x][i].b][v[y][j].b]+v[y][j].c);
			}
		}
		print(w[x]+ans+w[y]);
		putchar('\n');
	}
	return 0;
}
