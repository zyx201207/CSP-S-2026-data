#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	long long ans = 0;
	int l = 1, r = n;
	while (l < r)
	{
		if (c[l] == c[r])
		{
			l++;
			r--;
		}
		else
		{
			if (a[l] == a[r])
			{
				ans += a[l];
				l++;
				r--;
			}
			else
			{
				ans += min(a[l], a[r]);
				if (a[l] < a[r])
				{
					a[r] -= a[l];
					l++;
				}
				else
				{
					a[l] -= a[r];
					r--;
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
