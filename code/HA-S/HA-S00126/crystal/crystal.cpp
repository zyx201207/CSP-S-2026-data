#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005];
ll l, r, mid, s[500005], ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		s[i] = a[i] + s[i - 1];
		l = 1, r = i;
		while(l < r)
		{
			mid = (l + r) / 2;
			if((i - mid + 1)*a[i] - (s[i] - s[mid - 1]) <= m)
			{
				r = mid;
			}
			else l = mid + 1;
		}
//		cout << i << ' ' << l << endl;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}

