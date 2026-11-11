#include<bits/stdc++.h>
using namespace std;
bool x[501],y[501],p;
int minn;
int n,m,d,q,w[500001],k[1001],a[1001][501],t[1001][501],r[100001][2],ans;
bool ss(int i,int j) 
{
	for(int kk=1;kk<=k[j];kk++)
		if(i==a[k[j]][kk])
			return 1;
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ans,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[k[i]][j],&t[k[i]][j]);
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		p=0;
		minn=10000001;
		memset(x,0,sizeof(0));
		memset(y,0,sizeof(0));
		scanf("%d%d",&r[i][1],&r[i][2]);
		for(int j=1;j<=n;j++)
		{
			if(ss(r[i][1],j))
				x[j]=1;
			if(ss(r[i][2],j))
				y[j]=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(x[j]&&y[j])
			{
				ans=t[r[i][1]][j]+t[r[i][2]][j];
				p=1;
			}
		}
		ans+=w[r[i][1]]+w[r[i][2]];
		printf("%d\n",ans);
	}
}
