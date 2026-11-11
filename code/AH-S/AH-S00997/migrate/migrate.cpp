#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using  namespace std;

typedef long long LL;

const int N = 5010, INF = 0x3f3f3f3f;

int c, t, n;
LL d;
LL pos[N];
int f[N][N], r[N][N], g[N][N];
int v[6];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	if(c <= 10)
	{
		while (t -- )
		{
			scanf("%d%lld", &n, &d);
			for (int i = 0; i <= n; i ++ )
				for (int j = 0; j <= n; j ++ )
					f[i][j] = g[i][j] = r[i][j] = INF;
			
			for (int i = 1; i <= n; i ++ ) scanf("%lld", &pos[i]);
			
			for (int i = 1; i <= n; i ++ )
			{
				f[i][i] = 0;
				for (int j = i + 1; j <= n; j ++ )
				{
					if(pos[j] - pos[i] <= d) f[i][j] = 1;
				}
			}
			for (int k = 1; k <= n; k ++ )
				for (int i = 1; i <= n; i ++ )
					for (int j = 1; j <= n; j ++ )
					{
						if(i == j || i == k || j == k) continue;
						
						v[0] = f[i][k] + f[k][j]; v[1] = f[i][j];
						v[2] = f[i][k] + g[k][j]; v[3] = g[i][k] + f[k][j];
						v[4] = g[i][j]; v[5] = r[i][j];
						sort(v, v + 6);
						f[i][j] = v[0]; g[i][j] = v[1]; r[i][j] = v[2];
					}
					
			long long ans = 0;
			for (int i = 1; i <= n; i ++ )
				for (int j = i + 1; j <= n; j ++ )
					if(f[i][j] == g[i][j] && g[i][j] != r[i][j]) ans ++;
			printf("%lld\n", ans);
		}
		return 0;
	}
	if(c == 11 || c == 12)
	{
		while (t -- )
		{
			scanf("%d%lld", &n, &d);
			
			LL m;
			for (int i = 1; i <= n; i ++ ) scanf("%lld", &pos[i]);
			m = pos[2] - pos[1];
			
			if(m > d) { puts("0"); continue; }
			LL k = d / m;
			
			if(k == 1) {puts("0"); continue; }
			
			if(k == 2) printf("%d\n", max(0, n - 3));
			if(k > 2) printf("%d\n", k - 1);
		}
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/
