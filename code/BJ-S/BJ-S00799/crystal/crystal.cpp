#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n, cnt, ans;
long long m, tmp;
long long a[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	tmp = m;
	int l = 1, r = 1;
	while (l <= r && r <= n)
	{
		if (m >= 0)
		{
			m -= (r-l+1)*(a[r+1]-a[r]);
			r++;
			if (m >= 0 && r-l+1 > ans)
				ans = r-l+1;
		}
		else
		{
			m += a[r] - a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
}
