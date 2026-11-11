#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n, m, a[N], ans = -1;
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1;i <= n;i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	cout << ans << endl;
	for (int i = 1;i <= n - m;i++)
	{
		long long ans1 = (a[i] & a[i + 1]);
		for (int j = i + 2;j <= i + m - 1;j++)
		{
			ans1 = (ans1 & a[i]);
		}
		ans = max(ans, ans1);
	}
	cout << ans;
	return 0;
}
/*
卑鄙我去吧瞬间就爱上雷神
yellow and purple 小 fish
*/

