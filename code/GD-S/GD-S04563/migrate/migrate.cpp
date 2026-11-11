#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N6 = 3e2 + 5, NA = 2e6 + 5;
int c, t, n;ll d, x[NA];
ll ans;

int mp[N6][N6];
ll cnt[N6][N6];
void init()
{
	memset(mp, 0x3f, sizeof(mp)), memset(cnt, 0, sizeof(cnt));
	for(int u = 1;u < n;u++)
		for(int v = u + 1;v <= n;v++)
			if(x[v] - x[u] <= d)
				mp[u][v] = mp[v][u] = 1, cnt[u][v] = cnt[v][u] = 1;
	for(int i = 1;i <= n;i++)mp[i][i] = 0;
}
void floyd()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
			{
				if(mp[i][k] + mp[k][j] < mp[i][j])mp[i][j] = mp[i][k] + mp[k][j], cnt[i][j] = 1ll * cnt[i][k] * cnt[k][j];
				else if(mp[i][k] + mp[k][j] == mp[i][j])cnt[i][j] += 1ll * cnt[i][k] * cnt[k][j];
			}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	x[0] = -2e18;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 1;i <= n;i++)scanf("%lld", &x[i]);
		if(c <= 6)
		{
			init(), floyd();
			for(int l = 1;l < n;l++)
				for(int r = l + 1;r <= n;r++)
					ans += cnt[l][r] == 2;
			/*
			for(int l = 1;l <= n;l++)
			{
				int cnt = 0, len = 1, lst = l, llst = 0;
				for(int r = l;r <= n;r++)
				{
					if(x[r] - x[l] <= d)continue;
					if(d < x[r] - x[lst])
					{
						if(len > 1)
						{
							if(x[r - 1] - x[lst - 2] <= d)break;
							else if(x[r - 1] - x[lst - 1] <= d)
							{
								cnt++;
								if((len > 2 && x[lst - 1] - x[llst - 1] <= d) || cnt > 1)
									break;
							}
						}
						llst = lst, lst = r - 1, len++;
					}
					if(x[r] - x[lst - 2] <= d)continue;
					if(x[r] - x[lst - 1] <= d)
					{
						if(cnt)continue;
						if(len > 2 && x[lst - 1] - x[llst - 1] <= d)
							continue;
					}
					else continue;
					ans++;
				}
			}
			*/
		}
		else if(11 <= c && c <= 12)
		{
			int len;
			for(len = 1;len < n;len++)
				if(x[len + 1] - x[1] > d)
					break;
			len--, len = 2 * len - 1;
			ans = (2 < len && len <= n) ? n - len : 0;
		}
		else if(13 <= c && c <= 14)
		{
			int cnt = 0, pos = 0;
			for(int i = 1;i <= n;i++)
				if(x[i] - x[1] <= d && x[n] - x[i] <= d)
					cnt++, pos = i;
			if(cnt == 2)ans = 1ll * (n - pos) * (pos - 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
