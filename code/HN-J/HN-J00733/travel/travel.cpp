#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
unordered_map<char, bool> mp{{'A', 1}, {'B', 1}, {'C', 1}, {'D', 0}, {'F', 0}};
unordered_map<char, int> mp2{{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'F', 5}};
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2;
	int pi1, pi2;
	char pos1, pos2;
	cin >> c1 >> pi1 >> pos1 >> c2 >> pi2 >> pos2;
	bool ans1 = (c1 == c2);
	bool ans2 = (ans1 and pi1 == pi2);
	bool ans3 = (ans2 and mp[pos1] == mp[pos2]);
	bool ans4 = (ans3 and abs(mp2[pos1] - mp2[pos2]) == 1);
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}

