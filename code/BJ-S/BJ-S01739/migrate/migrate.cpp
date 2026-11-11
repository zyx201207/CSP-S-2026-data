/*
 海上有 n 座岛屿,自北向南排成一条直线,其中第 i (1 ≤ i ≤ n) 座岛屿在这条直
线上的坐标为整数 x i ,且 x 1 < x 2 < · · · < x n 。每年秋季,一群海鸟会沿着这条直线在
南北方向上迁徙,小 P 正在观察它们。
海鸟的体力有限,每次飞行的距离都不超过 d。若两座岛屿 i, j (1 ≤ i, j ≤ n) 满足
|x i − x j | ≤ d,海鸟就可以从第 i 座岛屿直接飞到第 j 座岛屿。
对于两座不同的岛屿 u, v (1 ≤ u, v ≤ n),一条从第 u 座岛屿到第 v 座岛屿的路径
形如 y 1 → y 2 → · · · → y m ,其中 y 1 = u,y m = v,且对于所有 l (1 ≤ l ≤ m − 1),海鸟
都能够从第 y l 座岛屿直接飞到第 y l+1 座岛屿;其长度为 m − 1,即海鸟在路径中飞行
的次数。
小 P 发现,海鸟在迁徙时总是会选择长度最短的路径。对于两座岛屿 u, v (1 ≤ u <
v ≤ n),若从第 u 座岛屿到第 v 座岛屿的长度最短的路径 恰
. 好有两条,海鸟可以分成两
.
群,分别沿其中一条飞往第 v 座岛屿;此时称 (u, v) 为 双
. 径
. 岛
. 屿
. 对。两条路径不同,当
.
且仅当它们经过的岛屿序列不完全相同。
你需要帮助小 P 求出双径岛屿对的数量。
 */ 
#include "bits/stdc++.h"
#define int long long
using namespace std;
int ccf, T, n, d, a[2000005], l[2000005], r[2000005], dp[5005], dis[5005], ans;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> ccf >> T;
	while(T--)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if(ccf <= 6)
		{
			for(int i = 1;i <= n;i++)
			{
				dis[i] = 0, dp[i] = 1;
				for(int j = i + 1;j <= n;j++)
				{
					dp[j] = 0;
					dis[j] = 0x3f3f3f3f;
				}
				for(int j = i;j <= n;j++)
				{
					for(int k = j + 1;k <= n;k++)
					{
						if(a[k] - a[j] <= d)
						{
							if(dis[k] > dis[j] + 1)
							{
								dis[k] = dis[j] + 1;
								dp[k] = dp[j];
							}else if(dis[k] == dis[j] + 1)
							{
								dp[k] += dp[j];
							}
						}
					}
					if(dp[j] == 2)
					{
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}else
		{
			for(int i = 1;i <= n;i++)
			{
				int up = a[i] + d;
				int upx = upper_bound(a + 1, a + n + 1, up) - a - 2;
				if(upx > i)
				{
					int up2 = a[upx] + d;
					int upx2 = upper_bound(a + 1, a + n + 1, up2) - a - 1;
					int upx3 = max(upx2, upx + 2);
					if(upx - 1 > i)
					{
						int up3 = a[upx - 1] + d;
						upx3 = lower_bound(a + 1, a + n + 1, up3) - a + 1;
					}
					if(upx3 <= upx2)
					{
						l[i] = upx3, r[i] = upx2;
						ans += r[i] - l[i];
						//cout << i << ' ' <<l[i] << ' ' << r[i] << '\n';
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
