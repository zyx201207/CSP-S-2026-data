#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];

ll sum(int l, int r)
{
	return s[r] - s[l - 1];
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int p = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] < p) p = a[i];
	}
	for (int i = 1; i <= n; ++i)
		a[i] += p;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	
	int ans = 0;
	for (int i = 2; i <= n; ++i)
	{
		int l = 0, r = i, t = 0;
		while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if ((a[i] * mid) - sum(i - mid + 1, i) <= m)
			{
				t = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}
