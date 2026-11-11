#include<bits/stdc++.h>
using namespace std;
long long c,n,m,p,q,e[1000100],f[510][510],ji[510],d[1001000];
vector<pair<long long ,long long > >h[510]; 
vector<pair<long long ,long long > >a[1001000]; 
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&p,&q);
	for(long long i=1;i<=m;i++)scanf("%lld",&e[i]);
	memset(f,63,sizeof(f));
	for(long long i=1;i<=n;i++)
	{
		f[i][i]=0;
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++)
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			h[i].push_back({x,y});
			a[x].push_back({i,y});
		}
		ji[i]=k;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<ji[i];j++)
		{
			d[h[i][j].first]=h[i][j].second;
		}
		for(long long j=i+1;j<=n;j++)
		{
			for(long long k=0;k<ji[j];k++)
			if(d[h[j][k].first])
			{
				f[i][j]=f[j][i]=min(f[i][j],d[h[j][k].first]+h[j][k].second);
			}
		}
		for(long long j=0;j<ji[i];j++)
		{
			d[h[i][j].first]=0;
		}
	}
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
			if(k!=i)
			for(long long j=i+1;j<=n;j++)
			if(k!=j)
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		long long x,y,s,ss;
		scanf("%lld%lld",&x,&y);
		s=e[x]+e[y];
		long long n=a[x].size(),nn=a[y].size();
		ss=f[a[x][0].first][a[y][0].first]+a[x][0].second+a[y][0].second;
		for(long long i=0;i<n;i++)
			for(long long j=0;j<nn;j++)
				ss=min(ss,f[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second);
		printf("%lld\n",s+ss);
	}
}
