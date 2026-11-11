#include<bits/stdc++.h>
#define sc(x) scanf("%lld",&x)
#define int long long
using namespace std;
long long c,n,m,d,q,a,t,w[500005],k[505],id1,id2,da;
long long p[500005][23],s[500005][23],id[500005];
long long e[505][505];

void dfs(int x)
{
	for(int i=1;i<x;i++)
	{
		for(int j=x+1;j<=n;j++)
		{
			if(e[i][x]!=10000000000&&e[x][j]!=10000000000)
			{
				e[i][j]=min(e[i][j],e[i][x]+e[x][j]);
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			e[i][j]=100000000000000000;//1e10 
		} 
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	//存边 
	for(int i=1;i<=n;i++)
	{
		sc(k[i]);
		for(int j=1;j<=k[i];j++)
		{
			sc(a);sc(t);
			id[a]++;
			p[a][id[a]]=i;
			s[a][id[a]]=t;
		}
	}
	//建图 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=id[i];j++)
		{
			for(int ck=j+1;ck<=id[i];ck++)
			{
				e[p[i][j]][p[i][ck]]=min(e[p[i][j]][p[i][ck]],s[i][j]+s[i][ck]);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		dfs(i);
	}
	
	for(int i=1;i<=q;i++)
	{
		sc(id1);sc(id2);
		if(id1>id2)swap(id1,id2);
		da=100000000000000000;
		for(int i=1;i<=id[id1];i++)
		{
			for(int j=1;j<=id[id2];j++)
			{
				da=min(da,e[p[id1][i]][p[id2][j]]+w[id1]+w[id2]+s[id1][i]+s[id2][j]);
			}
		}
		printf("%lld\n",da);
	}
	return 0;
}
//e不搞最大没救了。 
