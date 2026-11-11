#include <bits/stdc++.h>
using namespace std;
long long a[200005], left, right, ans;
char s[200005], L, R;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> s[i];
	int l = 1, r = n;
	L = s[l], R = s[r];
	while (l <= r)
	{
		long long x += a[l], y += a[r];
		if (L == R) 
		{
			if (x > y)
			{
				r--;
				R = s[r];
				y = x - y;
				x = 0;
			}
			else if (y > x)
			{
				l++;
				L = s[l];
				x = y - x;
				y = 0;
			}
			else
			{
				l++;
				r--;
				y = x = 0;
				L = s[l], R = s[r];
			}
		}
		else
		{
			ans += min(x, y);
			if (x > y)
			{
				r--;
				R = s[r];
				y = x - y;
				x = 0;
			}
			else if (y > x)
			{
				l++;
				L = s[l];
				x = y - x;
				y = 0;
			}
			else
			{
				l++;
				r--;
				y = x = 0;
				L = s[l], R = s[r];
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
} 
