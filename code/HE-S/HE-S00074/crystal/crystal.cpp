#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
constexpr int N = 5e5 + 66;
ll a[N], n, m, su[N];
bool check(int mid)
{
	for(int i = 1, j = i + mid - 1;j <= n;i ++, j ++) if(mid * a[j] - (su[j] - su[i - 1]) <= m) return true;
	return false;
}
signed main()
{
	freopen("crystal.in", "r", stdin);freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++) su[i] = su[i - 1] + a[i];
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << '\n';
	return 0;
}
/*

二分答案???

*/
