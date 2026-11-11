#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n, ans = 0;
	while (l <= r)
	{
		if (c[l] != c[r])
		{
			if (a[l] > a[r])
			{
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			else
			{
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
		}
		else
		{
			if (a[l] > a[r])
			{
				a[l] -= a[r];
				r--;
			}
			else
			{
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout << ans << '\n';
    return 0;
}
