#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n;
long long c, ans, a[N];
char b[N];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	int l = 1, r = n;
	while (l <= r)
	{
		long long k = min(a[l], a[r]);
		if (b[l] != b[r]) ans += k;
		if (a[l] > a[r])
		{
			r--;
			a[l] -= k;
		}
		else if (a[r] > a[l])
		{
			l++;
			a[r] -= k;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
