#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 2e5 + 10;
const int inf = 0x3f3f3f3f;
ll n,a[w],s[w],ans;
char c[w];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	ll l = 1,r = n,lc = a[1],rc = a[n];
	while (l < r)
	{
		if (lc < rc)
		{
			if (c[l] != c[r])
				ans += lc;
			rc -= lc;
			l++;
			lc = a[l];
		}
		else if (lc > rc)
		{
			if (c[l] != c[r])
				ans += rc;
			lc -= rc;
			r--;
			rc = a[r];
		}
		else
		{
			if (c[l] != c[r])
				ans += lc;
			l++;
			r--;
			lc = a[l];
			rc = a[r];
		}
	}
	cout << ans;
	return 0;
}
//abbaacccddbbbbbccaa l = 5 r = 5 lc = 1 rc = 2 ans = 8
