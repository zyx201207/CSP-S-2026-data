#include<bits/stdc++.h>
using namespace std;
long long w[500005];
struct ff
{
	int x;
	long long z;
};
vector<ff> a[500005];
long long f[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int sid,n,m,d,q,x,y;
	long long z;
	scanf("%d%d%d%d%d",&sid,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%lld",&x,&z);
			a[x].push_back({i,z});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++)
	{
		for(ff j:a[i])
		{
			for(ff k:a[i])
			{
				if(j.x==k.x)continue;
				f[j.x][k.x]=min(f[j.x][k.x],j.z+k.z);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(ff i:a[x])
		{
			for(ff j:a[y])
			{
				ans=min(ans,f[i.x][j.x]+i.z+j.z);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans); 
	}
}
