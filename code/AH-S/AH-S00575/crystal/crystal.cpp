#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;
ll a[N], m;
ll b[N];
ll sum[N];
int c[N];
bool check(int x, int now)
{
	ll num = a[now] * (now - x + 1);
	num = num - (sum[now] - sum[x - 1]);
	return num <= m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int l = 1, r = i, best = -1;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid, i))
			{
				best = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		if (best != -1)
		{	
			ans = max(ans, i - best + 1);
		}
	}
	cout << ans;
	return 0;
}
