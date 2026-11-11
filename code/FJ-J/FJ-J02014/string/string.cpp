#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2 * 1e5 + 5;
string s;
ll a[MAXN];
char c[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i] >> c[i];
	ll ans = 0, l = 1, r = n, lj = 0, rj = 0;
	while(l < r)
	{
//		if (c[l] != c[r])
//		{
			ans += min(a[l], a[r]) * (c[l] != c[r]);
			if (a[l] > a[r])
			{
				a[l] -= a[r];
				-- r;
			}
			else if (a[l] < a[r])
			{
				a[r] -= a[l];
				++ l;
			}
			else if (a[l] == a[r])
			{
				++ l;
				-- r;
			}
//		}
	}
	cout << ans << '\n';
	return 0;
}
