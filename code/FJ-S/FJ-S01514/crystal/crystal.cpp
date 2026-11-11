#include<bits/stdc++.h>
using namespace std;
//void test()
//{
//	freopen("crystal.in", "r", stdin);
//	
//}
using ll = long long;
constexpr int N = 500005;
//unordered_map<ll, int> mp;
ll a[N], lnk[N];
int cnt;
int num[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll m;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n ; i++)
	{
//		if (!mp.count())
		if (a[i] != a[i - 1])
		{
			lnk[++cnt] = a[i];
//			num[cnt] = 1;
		}
		// remember!!!
		++ num[cnt];
	}
	int l = 1, r = 1, cur = 0, ans = 0;
	ll cs = 0;
	while (r <= cnt)
	{
		cs += 1ll * (lnk[r] - lnk[r - 1]) * cur;
		cur += num[r];
		while (l < r && cs > m)
		{
			// if the cost more than the m
			while (num[l] > 0 && cs > m)
			{
				-- cur;
				-- num[l];
				cs -= (lnk[r] - lnk[l]);
			}
			if (num[l] == 0)
				++ l;
		}
		++ r;
		ans = max(cur, ans);
	}
	cout << ans << '\n';
	return 0;
}
