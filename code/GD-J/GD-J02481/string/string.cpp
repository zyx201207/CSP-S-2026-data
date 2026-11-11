#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = 0;
	cin >> n;
	long long a[200010]{};
	char c[200010]{};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
	}
	long long l = a[0];
	long long lp = 0;
	char lc = c[0];
	long long r = a[n - 1];
	long long rp = n - 1;
	char rc = c[n - 1];
	long long ans = 0;
	while (lp < rp)
	{
		if (lc == rc)
		{
			if (l > r)
			{
				l -= r;
				rp--;
				r = a[rp];
				rc = c[rp];
			}
			else if (r > l)
			{
				r -= l;
				lp++;
				l = a[lp];
				lc = c[lp];
			}
			else
			{
				lp++;
				rp--;
				l = a[lp];
				lc = c[lp];
				r = a[rp];
				rc = c[rp];
			}
		}
		else
		{
			if (l > r)
			{
				ans += r;
				l -= r;
				rp--;
				r = a[rp];
				rc = c[rp];
			}
			else if (r > l)
			{
				ans += l;
				r -= l;
				lp++;
				l = a[lp];
				lc = c[lp];
			}
			else
			{
				ans += l;
				lp++;
				rp--;
				l = a[lp];
				lc = c[lp];
				r = a[rp];
				rc = c[rp];
			}
		}
	}
	cout << ans;
	
	return 0;
}
