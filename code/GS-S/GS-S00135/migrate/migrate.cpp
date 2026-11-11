#include <iostream>
const int N = 505,INF = 1e7;
typedef long long ll;
int f[N][N];
int nxt[N];
int dis[N][N];
ll x[N];
int main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = 0,T = 0;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n = 0;
		ll d = 0;
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
		for(int i = 1,j = 1;i <= n;i++)
		{
			if(j < i)j = i;
			while(j <= n && x[j] - x[i] <= d) j++;
			j--;
			nxt[i] = j;
		}
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				{
					int tmp = i;
					dis[i][j] = 0;
					for(int k = 1;k <= n + 1;k++)
						{
							tmp = nxt[tmp];
							dis[i][j]++;
							if(tmp >= j) break;
						}
					if(dis[i][j] > n) dis[i][j] = INF;
				}
		
		for(int i = 1;i <= n;i++)
			f[i][i] = 1;
		ll ans = 0;
		for(int len = 2;len <= n;len++)
			for(int i = 1;i + len - 1 <= n;i++)
			{
				int j = i + len - 1;
				f[i][j] = 0;
				if(dis[i][j] == INF) continue;
				for(int k = i + 1;k < j;k++)
					if(dis[i][k] + dis[k][j] == dis[i][j])
					f[i][j] += f[i][k] * f[k][j];
				if(dis[i][j] > 1) f[i][j] /= (dis[i][j] - 1);
				if(x[j] - x[i] <= d) f[i][j]++;
				if(f[i][j] > 2) f[i][j] = 10;
				if(f[i][j] == 2) ans++;
			}
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
