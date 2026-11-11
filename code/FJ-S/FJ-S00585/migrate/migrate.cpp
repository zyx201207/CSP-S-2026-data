#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005], ans[2000005];
bool vis[1005][1005];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c, t;
	cin >> c >> t;
	int pos = 1;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		int num = 0;
		for (int i=1;i<=n;i++) cin >> x[i];
		if (n <= 3)
		{
			ans[pos] = 0;
			pos++;
			break;
		}
		for (int i=1;i<=n;i++)
		{
			int cnt = 0;
			for (int j=1;j<=n;j++)
			{
				if (i - j > 0)
				{
					if (i - j < d && vis[i][j] == true && (i - j) * d == n)
					{
						cnt++;
						vis[i][j] = false;
					}
					else break;
				}
				else
				{
					if (j - i < d && vis[j][i] == true && (j - i) * d == n)
					{
						cnt++;
						vis[j][i] = false;
					}
					else break;
				}
			}
			if (cnt == 2) num++;
		}
		ans[pos] = num;
		pos++;
	}
	for (int i=1;i<=pos-1;i++) cout << ans[i] + 1 << endl;
	return 0;
}
//特殊性质 A：x1, x2, . . . , xn 构成等差数列. --> 8分. 
//特殊性质 B：存在一座岛屿，使得海鸟可以从该岛屿直接飞到任意其他岛屿. --> 8分.
//特殊性质 C：xn - x1 ≤10d. --> 12分.


//666，海上哪来这么多排成一条直线的岛屿？
//这难道是传说中的逆天动规题？太阴间了吧！ 
