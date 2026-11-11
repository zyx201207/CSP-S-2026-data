#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 5000 + 10;
int dis[N][N], cnt[N][N], a[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C = read(), T = read();
	if(C == 13 || C == 14)
	{
		while(T--)
		{
			int n = read(), d = read();
			for(int i = 1; i <= n; i++) a[i] = read();
			int ans = 0;
			for(int i = 1; i <= n; i++)
			{
				if(a[i] + d > a[n]) break;
				int fir = lower_bound(a + i, a + n + 1, a[i] + d) - a;
				int sec = n;
				if(a[i] + 2 * d <= a[n]) sec = lower_bound(a + i, a + n + 1, a[i] + 2 * d) - a;
				ans += sec - fir;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	while(T--)
	{
		int n = read(), d = read();
		memset(dis, 0x3f, sizeof dis);
		memset(cnt, 0, sizeof cnt);
		for(int i = 1; i <= n; i++)
		{
			a[i] = read();
			dis[i][i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				for(int k = j; k <= n; k++)
				{
					if(a[k] - a[j] <= d)
					{
						if(dis[i][k] > dis[i][j] + 1)
						{
							dis[i][k] = dis[i][j] + 1;
							cnt[i][k] = 1;
						}
						else if(dis[i][k] == dis[i][j] + 1) cnt[i][k]++;
					}
					else break;
				}
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(cnt[i][j] == 2) ans++;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
ans:1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
ans:0
1
*/
inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
