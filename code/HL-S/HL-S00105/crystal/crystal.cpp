#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long m,n;
long long a[N],d[N];
long long dd[N];
bool check(long long x)
{
	long long sum = 0;
	for (long long i = 2;i <= x;i++)
	{
		sum += d[i] * (i - 1);
	}
	return sum <= n;
}
bool dc()
{
	for (int i = 3;i <= m;i++)
	{
		dd[i] = d[i] - d[i - 1];
	}
	for (int i = 2;i <= m;i++)
	{
		if (dd[i] != 0) return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> m >> n;
	for (int i = 1;i <= m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + m + 1);
	for (int i = 1;i <= m;i++)
	{
		d[i] = a[i] - a[i - 1];
	}
	if (dc())
	{
		long long c = d[2],sum = 0;
		for (long long i = 1;i <= m - 1;i++)
		{
			sum += c * i;
			if (sum == n) {cout << i + 1;return 0;}
			if (sum > n) {cout << i;return 0;}
		}
		cout << m;
		return 0;
	}
	long long l = 1,r = m,ans;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
