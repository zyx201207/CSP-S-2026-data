#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e5 + 10;

int n;
string s = " ";

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n;
	for (int i = 1, x; i <= n; ++i)
	{
		char y; cin >> x >> y;
		for (int j = 1; j <= x; ++j) s.push_back(y);
	}
	int ans = 0;
	for (int i = 1; i <= s.size() / 2; ++i) if (s[i] != s[s.size() + 1 - i]) ++ans;
	cout << ans;
	return 0;
}

/*
3
2 a
2 b
1 c
*/

