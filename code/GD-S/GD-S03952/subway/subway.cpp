#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,w[500005],z[500005],k,a,map1[505][505],x,y,s;
vector<long long>f[500005],t[500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			if(i!=j)
			{
				map1[i][j]=INT_MAX;
			}
		}
	}
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
		f[i].push_back(0);
		t[i].push_back(0);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld",&a);
			z[a]++;
			f[a].push_back(i);
			t[a].push_back(0);
			scanf("%lld",&t[a][z[a]]);
			for(int l=1;l<=z[a];l++)
			{
				map1[f[a][l]][i]=map1[i][f[a][l]]=min(map1[i][f[a][l]],t[a][l]+t[a][z[a]]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=n;l++)
			{
				map1[i][j]=map1[j][i]=min(map1[i][j],map1[i][l]+map1[l][j]);
				map1[i][l]=map1[l][i]=min(map1[i][l],map1[i][j]+map1[j][l]);
				map1[l][j]=map1[j][l]=min(map1[l][j],map1[l][i]+map1[i][j]);
			}
		}
	}
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		s=INT_MAX;
		for(int i=1;i<=z[x];i++)
		{
			for(int j=1;j<=z[y];j++)
			{
				s=min(s,map1[f[x][i]][f[y][j]]+t[x][i]+t[y][j]);
			}
		}
		printf("%lld\n",s+w[x]+w[y]);
	}
}


