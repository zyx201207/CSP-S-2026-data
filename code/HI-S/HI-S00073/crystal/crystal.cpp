#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

static long long n, m;
static vector<long long> a;

int main(void)
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (long long i = n - 1; i >= 0; i--)
	{
		long long num;
		long long cnt = 0;
		long long cnt2 = 0;
		for (long long j = i - 1; j >= 0; j--)
		{
			num = a[j];
			while (num < a[i] && cnt < m)
			{
				++num;
				++cnt;
			}
			if (num == a[i])
			{
				if (!cnt2)
					cnt2 = 2;
				else
					++cnt2;
			}
			if (cnt >= m)
				break;
		}
		ans = max(ans, cnt2);
	}
	cout << ans << endl;
	return 0;
}
