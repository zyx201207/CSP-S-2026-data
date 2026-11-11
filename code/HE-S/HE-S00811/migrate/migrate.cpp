#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e6 + 20;

int c, t;
int n, d;
int a[N];
int sum;
bool vis[5500][5500];
int ans[N];
int ma;
int cnt;

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}
		if (n <= d)
		{
			cout << "0" << '\n';
			continue;
		}
		int mi = n / d + 1;
		for (int i = 1; i < n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				memset(ans, 0, sizeof ans);
				int st = i;
				int en = j;
				sum = 0;
				for (int l = 1; l <= j; l ++)
				{
					for (int o = 1; o <= d; o ++)
					{
						vis[l][o] = 0;
					}
				}
				for (int k = d; k >= 1; k --)
				{
					if (st == en) break;
					if (a[en] - a[st] > d) continue;
					if (st + k > en) continue;
					sum ++;
					if (vis[sum][k])
					{
						sum --;
						st -= k;
						continue;
					}
					vis[sum][k] = 1;
					st += k;
					if (st + k <= en) k ++;
				}
				ma = max(ma, sum);
				ans[sum] ++;
			}
			for (int k = 1; k <= ma; k ++)
			{
				if (ans[sum] == 2)
				{
					cnt ++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
/*
	cnm的没时间改了 
*/
