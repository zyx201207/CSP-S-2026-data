#include<bits/stdc++.h>
using namespace std;
const int N=500+5,M=500000+5,D=20+5;
unsigned long long c,n,m,d,q,w[M],k[N],a[N][D],t[N][D],x,y,ans,
	PLcnt[M],PLcntU[M][D],disPL[M][D],toL[M][D],disL[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(PLcntU[a[i][j]][i]==0)
			{
				PLcnt[a[i][j]]++;
				disPL[a[i][j]][PLcnt[a[i][j]]]=t[i][j];
				toL[a[i][j]][PLcnt[a[i][j]]]=i;
				PLcntU[a[i][j]][i]=PLcnt[a[i][j]];
			}
			else disPL[a[i][j]][PLcntU[a[i][j]][i]]=min(disPL[a[i][j]][PLcntU[a[i][j]][i]],t[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			disL[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++) disL[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<PLcnt[i];j++)
			for(int l=j+1;l<=PLcnt[i];l++)
			{
				disL[toL[i][j]][toL[i][l]]=min(disL[toL[i][j]][toL[i][l]],
					disPL[i][j]+disPL[i][l]);
			}
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				disL[i][j]=min(disL[i][j],
					min(disL[i][l]+disL[l][j],disL[j][l]+disL[l][i]));
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		ans=LONG_LONG_MAX;
		for(int i=1;i<=PLcnt[x];i++)
			for(int j=1;j<=PLcnt[y];j++)
				ans=min(ans,disL[toL[x][i]][toL[y][j]]+disPL[x][i]+disPL[y][j]);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
