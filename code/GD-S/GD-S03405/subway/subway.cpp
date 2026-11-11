#include<bits/stdc++.h>
using namespace std;
const long long inf=10000000000000000;
long long c,n,m,d,q,w[1000009],L[1000009],a[1000009][29],b[1000009][29],dis[509][509],len,q1,q2,ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&len);
		for(int j=1;j<=len;++j)
		{
			scanf("%lld%lld",&q1,&q2);
			++L[q1];
			a[q1][L[q1]]=i;
			b[q1][L[q1]]=q2;
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=L[i];++j)
		{
			for(int k=j+1;k<=L[i];++k)
			{
				if(b[i][j]+b[i][k]<dis[a[i][j]][a[i][k]])
				{
					dis[a[i][j]][a[i][k]]=b[i][j]+b[i][k];
					dis[a[i][k]][a[i][j]]=b[i][j]+b[i][k];
				}
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%lld%lld",&q1,&q2);
		ans=inf;
		for(int j=1;j<=L[q1];++j)
		{
			for(int k=1;k<=L[q2];++k)
			{
				if(b[q1][j]+b[q2][k]+dis[a[q1][j]][a[q2][k]]<ans)
				{
					ans=b[q1][j]+b[q2][k]+dis[a[q1][j]][a[q2][k]];
				}
			}
		}
		ans+=w[q1]+w[q2];
		printf("%lld\n",ans);
	}
	return 0;
}
