#include<bits/stdc++.h> 
using namespace std;
long long c,n,m,dd,q,w[500005],d[505][505];
int j[500005];
struct zzz{
	int p;
	long long t;
}a[500005][25];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&dd,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int o=1;o<=k;o++)
		{
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			j[aa]++;
			a[aa][j[aa]].p=i;
			a[aa][j[aa]].t=tt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int o=1;o<=n;o++)
		d[i][o]=1e18;
	}
	for(int i=1;i<=m;i++)
	{
		for(int o=1;o<=j[i];o++)
		{
			for(int k=o+1;k<=j[i];k++)
			d[a[i][o].p][a[i][k].p]=d[a[i][k].p][a[i][o].p]=min(d[a[i][k].p][a[i][o].p],a[i][o].t+a[i][k].t);
		}
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int o=1;o<=n;o++)
		{
			for(int j=o;j<=n;j++)
			{
				d[o][j]=d[j][o]=min(d[o][j],d[o][i]+d[i][j]);
			}
		}
	}
	for(;q--;)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=1e18;
		for(int i=1;i<=j[u];i++)
		{
			for(int o=1;o<=j[v];o++)
			{
				//cout<<a[u][i].p<<" "<<a[v][o].p<<" "<<d[a[u][i].p][a[v][o].p]<<endl;
				ans=min(ans,d[a[u][i].p][a[v][o].p]+a[u][i].t+a[v][o].t);//
			}
		}
		ans+=w[u]+w[v];
		printf("%lld\n",ans);
		//cout<<ans<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
