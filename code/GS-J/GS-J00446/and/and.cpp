#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5, mod = 998244353;
int n, m, a[N];
bool check(int x)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if ((a[i] & x) != x) continue;
		res++;
	}
	return res >= m;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 29; i >= 0; i--)
	{
		if (check(ans | (1 << i)))
		{
			ans |= 1 << i;
		}
	}
	cout << ans;
	return 0; 
}
// 居然是模板贪心？8.53 写完前三题优势在我 
