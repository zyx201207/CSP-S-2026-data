#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5 + 10;
int n, ans, L, max_ai = -1e18;
char c[MAXN];
int a[MAXN];
string str;
signed solve1()
{
	int l = 1, r = n;
	while (l <= r)
	{
		// 先计算这一段的答案 
		if (c[l] != c[r])    ans += min(a[l], a[r]);
		// 更新l、r
		if (a[l] < a[r])    a[r] -= a[l], l++;
		else if (a[r] < a[l])    a[l] -= a[r], r--;
		else if (a[l] == a[r])    l++, r--;
	}
	cout << ans << endl;
	return 0;
}
signed main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		max_ai = max(max_ai, a[i]);
	}
	if (n * max_ai >= 5e7)    return solve1();
	for (int i = 1; i <= n; i++)    for (int cnt = 1; cnt <= a[i]; cnt++)    str.push_back(c[i]);
	L = str.size(), str = ' ' + str;
	int l = 1, r = L;
	while (l <= r)
	{
		if (str[l] != str[r])    ans++;
		l++, r--;
	}
	cout << ans << endl;
	return 0;
}

