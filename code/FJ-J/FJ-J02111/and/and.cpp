#include <bits/stdc++.h>
#define int long long
const int maxn = 2e5 + 5;
using namespace std;
int n, m, a [maxn], vis [maxn], baol [maxn];
int ans, nowans;
//void dfs (int x)
//{
//	int y = a [x];
//	if (x > m)
//	{
//		ans = max (ans, nowans);
//		return;
//	}
//	cout << a [x] << " " << x << " " << m << " \n";
//	for (int i = 1; i <= n; i ++)
//	{
//		if (x == 1)
//		{
//			ans = a [x];
//		}
//		else
//		{
//			ans = ans & a [x];
//		}
//		if (vis [i] != 1)
//		{
//			vis [i] = 1;
//			dfs (i + 1);
//			vis [i] = 0;
//		}
//	}
//}
//int baoli (int m, int a [])
//{
//	int ans;
//	for (int i = 1; i <= m; i ++)
//	{
//		for (int j = 1; j <= m; j ++)
//		{
//			int nowans = i & j;
//			ans = max (ans, nowans);
//		}
//	}
//	return ans;
//}
void baoli (int a [], int cengshu)
{
	if (cengshu == m)
	{
//		cout << "ÐÐ51 cengshu " << cengshu << "\n";
		for (int i = 2; i <= m; i ++)
		{
			if (vis [i] == 1)
			{
				if (i == 2)
				{
					nowans = baol [2] & baol [1];
					continue;
				}
	//			cout << nowans << " " << baol [i] << "\n";
				nowans = nowans & baol [i];
				}
				ans = max (nowans, ans);
			}
//		cout << ans << "\n";
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (vis [i] == 0)
		{
//			cout << "ÐÐ64 cengshu " << cengshu << "\n";
			baol [cengshu + 1] = a [i];
			baoli (a, cengshu + 1);
			baol [cengshu + 1] = 0;
			vis [i] = 1;
//			cout << "ÐÐ70\n";
		}
	}
}
signed main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("ans.out", "w", stdout);
	bool tepanA = 0, tepanA_no = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a [i];
		if (((a [i] & 32767 ) )== a [i] && (tepanA_no = 0))
		{
			tepanA = 1;
		}
		else
		{
			tepanA = 0, tepanA_no = 1;
		}
	}
	if (tepanA == 1)
	{
		sort (a + 1, a + n + 1);
		cout << a [n - 1];
		return 0;
	}
	baoli (a, 0);
	cout << ans;
	return 0;
}
