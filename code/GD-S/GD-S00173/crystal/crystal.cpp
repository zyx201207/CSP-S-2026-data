#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define ll long long
ll a[N], m, ans, cnt[N];
int n;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		ll l = 1, r = i, mid;//固定右端点，枚举左端点 
		int id = i;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if((i - mid) * a[i] - (cnt[i - 1] - cnt[mid - 1]) <= m)
			{
				r = mid - 1;
				id = mid;
			}
			else l = mid + 1;
		}
		ans = max(ans, (ll)i - id + 1);
	}
	cout << ans << "\n";
	return 0;
} 
