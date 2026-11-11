#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n, m;
int a[N];
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	__int128 cnt = 0;
	int l = 1;
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) 
	{
		cnt += (__int128) (i - l) * (a[i] - a[i - 1]);
		while (cnt > m)
		{
			cnt -= a[i] - a[l];
			l ++ ;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return ;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

