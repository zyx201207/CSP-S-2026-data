#include <iostream>
#include <cstdio>
using namespace std;
constexpr int N = 2e5 + 5;
long long a[N], ans = ~0x7FFFFFFF, mx = ~0x7FFFFFFF;
int n, m;
void di(long long res, int sum)
{
	if (sum == m)
	{
		ans = max(ans, res);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		di(res & a[i], sum + 1);
	}
	return;
}
int duanchu(long long mx)
{
	int num = 0;
	long long ans = 0, a = 1;
	while (mx != 1)
	{
		mx /= 2;
		num++;
	}
	for (int i = 0; i <= num; i++)
	{
		a = 1;
		for (int j = 1; j <= i; j++)
		{
			a *= 2;
		} 
		ans += a; 
	}
	return ans;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	} 
	di(duanchu(mx), -1);
	cout << ans;
	return 0;
}
