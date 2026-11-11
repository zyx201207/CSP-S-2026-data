#include <bits/stdc++.h>
using namespace std;

int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long ans = 1;
	long long a[n + 1];
	for (long long i = 1; i <= n; i++)
		scanf ("%lld",&a[i]);
	sort (a + 1, a + n + 1);
	long long l = 1,r = 1;
	for (long long i = 2; i <= n; i++)
	{
		m -= 1ll * (a[i] - a[i - 1]) * (r - l + 1);
		r++;
		if (m >= 0) ans = max (ans, r - l + 1);
		while (m < 0) {
			m += a[r] - a[l];
			l++;
		}
	}
	cout << ans << endl;
	return 0;
}
