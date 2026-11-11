/*
小 R 有 n 个非负整数 a 1 , a 2 , . . . , a n 。
小 X 给了小 R 一个正整数 m,并要求小 R 从这 n 个非负整数中选出 恰
. 好
. m 个,
使得选出的 m 个数的 二
. 进
. 制
. 按
. 位
. 与的值最大。
.
你需要帮助小 R 求出,他能选出的 m 个数的按位与的最大值。
*/
#include "bits/stdc++.h"
#define int long long
using namespace std;
int n, m, a[200005], vis[300005], cnt, ans;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		vis[i] = 1; 
	}
	for(int i = 30;i >= 0;i--)
	{
		cnt =0;
		int msk = (1ll << i);
		for(int j = 1;j <= n;j++)
		{
			if((a[j] & msk) && (vis[j]))
			{
				cnt++;
			}
		}
		if(cnt >= m)
		{
			for(int j = 1;j <= n;j++)
			{
				if((a[j] & msk) && (vis[j]))
				{
					vis[j] = 1;
				}else
				{
					vis[j] = 0;
				}
			}
			ans += msk;
		}
	}
	cout << ans;
	//cout << "Hello, World!";
	return 0;
}
