#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
long long n, m, a[MAXN], r, l, ans, deta;
bool cmp(long long x, long long y)
{
	return x > y;
} 
void cheak(int x)
{
	long long mm = m, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		long long y = x - a[i];
		if (y < 0)
			continue;
		mm -= y;
		cnt++;
		if (mm < 0)
		{
			cnt--;
			break;
		}
	}
	if (cnt >= ans)
	{
		ans = cnt;
	}
	return ;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	l = 1e18;
	r = -1e18;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	deta = a[1] - a[2]; 
	bool B = true;
	for (int i = 3; i <= n; i++)
	{
		if (a[i - 1] - a[i] != deta)
		{
			B = false;
			break;
		}
	}
	if (B)
	{
		l = 1; r = n;
		while(l <= r)
		{
			long long mid = (l + r) >> 1;
			if (mid * (mid + 1) * deta <= m * 2)
			{
				ans = max(ans, mid + 1);
				l = mid + 1; 
			}
			else
				r = mid - 1;
		} 
	}
	else if ((n - 1) * (r - l) <= m)
		ans = n;
	else
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i - 1])
				cheak(a[i]);
	
	cout << ans;
	return 0;
} //O(n * a) 90
