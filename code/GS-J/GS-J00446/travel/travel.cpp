#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5, mod = 998244353;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "0000";
	if (c1 == c2) ans[0] = '1';
	if (ans[0] == '1')
	{
		if (s1.substr(0, 2) == s2.substr(0, 2)) 
		{
			ans[1] = '1';
		}
	}
	char a = s1.back(), b = s2.back();
	if (ans[1] == '1')
	{
		if (a < 'D' && b < 'D' || a >= 'D' && b >= 'D') 
		{
			ans[2] = '1';
		}
	}
	if (a > b) swap(a, b);
	if (ans[1] == '1' && ans[2] == '1')
	{
		if (a == 'A' && b == 'B' || a == 'B' && b == 'C' || a == 'D' && b == 'F') 
		{
			ans[3] = '1';
		}
	}
	cout << ans;
	return 0; 
}
