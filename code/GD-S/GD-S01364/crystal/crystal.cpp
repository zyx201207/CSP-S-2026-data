#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long LL;
LL n, m, a[N], s[N];
bool check(LL x)
{
	for (LL i = 1; i + x - 1 <= n; i++)
	{
		LL sum = (s[i + x - 1] - s[i - 1]);
		if (a[i + x - 1] * x - sum <= m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (LL i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (LL i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	LL l = 1, r = n, ans = 0;
	while (l <= r)
	{
		LL mid = l + ((r - l) >> 1);
		if (check(mid)) {l = mid + 1; ans = mid;}
		else r = mid - 1; 
	}
	cout << ans;
	return 0;
 } 
