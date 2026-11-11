#include<bits/stdc++.h>
#define int long long
#define Furina using
#define de namespace
#define Fontaine std
Furina de Fontaine;
int constexpr Inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3fll;
int c,n,m,d,q,a[514191],b[514191],dis[514][514],s,e;
int tot=1,head[1145141],nxt[1145141],ed[1145141],val[1145141];
vector<int> v[514191],w[514191];
void add(int x,int y,int z)
{
	tot++;
	ed[tot]=y,val[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
void chkmn(int& x,int y)
{
	if(y<x)
	{
		x=y;
	}
}
int solve(int x,int y)
{
	int res=INF;
	for(int i=head[x+n];i>0;i=nxt[i])
	{
		for(int j=head[y+n];j>0;j=nxt[j])
		{
			chkmn(res,val[i]+val[j]+dis[ed[i]][ed[j]]);
		}
	}
	return res+a[x]+a[y];
} 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,Inf,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		scanf("%lld",b+i);
		v[i].resize(b[i]+1);
		w[i].resize(b[i]+1);
		for(int j=1;j<=b[i];j++)
		{
			scanf("%lld%lld",&v[i][j],&w[i][j]);
			add(v[i][j]+n,i,w[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=head[i+n];j>0;j=nxt[j])
		{
			for(int k=nxt[j];k>0;k=nxt[k])
			{
				chkmn(dis[ed[j]][ed[k]],val[j]+val[k]);
				dis[ed[k]][ed[j]]=dis[ed[j]][ed[k]];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				chkmn(dis[j][k],dis[j][i]+dis[i][k]);
				dis[k][j]=dis[j][k];
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			cerr<<"dis "<<i<<" "<<j<<":"<<dis[i][j]<<"\n";
//		}
//	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&s,&e);
		printf("%lld\n",solve(s,e));
	}
	return 0;
}
