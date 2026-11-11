#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##KON = (r); i <= i##KON; ++i)
#define per(i, l, r) for(int i = (l), i##KON = (r); i >= i##KON; --i)
using namespace std;
using ll = long long;
constexpr int N{1000005};
ll n, m, a[N], s[N];
ll to(int l, int r)
{
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int j = 1, ans = 0;
	rep(i, 1, n)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n)
	{
		s[i] = s[i - 1] + a[i];
		for(; j < i && to(j, i) > m; ++j);
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}