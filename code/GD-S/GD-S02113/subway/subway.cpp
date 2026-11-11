#include <bits/stdc++.h>
using namespace std;

long long w[500005];
long long dis[505][505];
long long a[500005][25],b[500005][25];
int cnt[500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++) dis[i][j] = dis[j][i] = 1e18;
	}
	for(int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			a[x][++cnt[x]] = i;
			b[x][cnt[x]] = y;
		 } 
	}
	for(int x = 1;x <= m;x++)
	{
		for(int j = 1;j <= cnt[x];j++)
		{
			for(int k = j + 1;k <= cnt[x];k++)
			{
				dis[a[x][j]][a[x][k]] = dis[a[x][k]][a[x][j]] = min(dis[a[x][j]][a[x][k]],b[x][j] + b[x][k]);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				dis[j][i] = dis[i][j] = min(dis[i][j],dis[i][k] + dis[j][k]);
			}
		} 
	}
	for(int i = 1;i <= q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans = 1e18;
		for(int j = 1;j <= cnt[x];j++)
		{
			for(int k = 1;k <= cnt[y];k++)
			{
				ans = min(ans,dis[a[x][j]][a[y][k]] + b[x][j] + b[y][k]);
			}
		}
		printf("%lld \n",ans + w[x] + w[y]);
	}
	return 0;
}
