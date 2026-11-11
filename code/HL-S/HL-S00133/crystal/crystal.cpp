#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long n, m, a[N], ans, z = 1, w = 1, r = 1, maxw = 1;
//bool check(long long t)
//{
//	for(int i = 0; i < n; i ++)
//	{
//		long long sum = 0, j = i + 1, cnt = 1;
//		while(sum <= m, j < n)
//		{
//			if(sum + a[j] - a[i] <= m) sum += (a[j] - a[i]), cnt ++, j ++;
//			else break;
//		}
//		if(cnt >= t)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
bool check(long long t)
{
	int x = t / 2;
	int y = t - x - 1;
	for(int i = x; i < n - y; i ++)
	{
		long long sum = 0;
		for(int j = i - x; j < i; j ++) sum += a[i] - a[j];
		for(int j = i + y; j > i; j --) sum += a[j] - a[i];
		if(sum <= m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i ++)
	{
		if(a[i] != i + 1)
		{
			z = 0;
			break;
		}
	}
	for(int i = 1; i < n; i ++)
	{
		if(a[i] == a[i - 1])
		{
			w ++;
			if(w > maxw) maxw = w;
		}
		else w = 1;
	}
	long long c = a[1] - a[0];
	for(int i = 1; i < n; i ++)
	{
		if(a[i] - a[i - 1] != c)
		{
			r = 0;
			break;
		}
	}
	if(maxw == n)
	{
		cout << n;
		return 0;
	}
	if(m == 0)
	{
		cout << maxw;
		return 0;
	}
	if(z == 1)
	{
		cout << min(n, m / 2 + 2);
		return 0;
	}
	if(r == 1)
	{
		if(m < c)
		{
			cout << 1;
			return 0;
		}
		cout << min(m / (2 * c) + 2, n);
		return 0;
	}
	long long left = 1, right = n, mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(check(mid))
		{
			left = mid + 1;
			ans = mid;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}
