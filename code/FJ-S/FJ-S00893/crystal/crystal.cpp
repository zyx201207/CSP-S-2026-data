#include <bits/stdc++.h>
using namespace std;
long long a[500005], s[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n, m;
	cin >> n >> m;
	bool f = 0;
	s[0] = 0;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i] - a[i - 1];
	}
	long long l = s[2];
	for(long long i = 3; i <= n; i++)
	{
		if(s[i] != l)
		{
			f = 1;
		}
	}
	sort(a + 1, a + n + 1);
	if(f == 0)
	{
		long long mm = m;
		long long ans = 0;
		while(mm > 0)
		{
			mm -= l;
			l *= 2;
			ans++;
		}
		cout << ans << endl;
	}
	else
	{
		bool v = 0;
		long long maxn = -1;
		for(long long i = 1; i <= n; i++)
		{
			if(v == 1)
			{
				break;
			}
			long long rm = m;
			for(long long j = 1; j <= i; j++)
			{
				if(a[j] != a[i])
				{
					rm -= abs(a[i] - a[j]);
				}
				if(rm < 0)
				{
					maxn = max(maxn, i - 1);
					v = 1;
					break;
				}
			}
			if(rm >= 0)
			{
				maxn = max(maxn, i);
			}
		}
		cout << maxn << endl;
	}
	return 0;
}

