#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500001];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = -1, l = 1, r = 1, aa = 0;
	while (r < n)
	{
		aa += (a[(++r)] - a[r - 1]) * (r - l);
		while(aa > m)
		{
			aa -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
 } 
