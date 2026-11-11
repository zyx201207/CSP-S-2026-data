#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s;
	int T;
	cin >> T;
	while(T --)
	{
		int x;
		char now;
		cin >> x >> now;
		for(int i = 1; i <= x; i ++) s += now;
	}
	string s2 = s;
	reverse(s2.begin(), s2.end());
	int size = s.size() - 1;
	int ans = 0;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s2[i] != s[i]) ans ++;
	}
	cout << ans / 2 << endl;
	return 0;
}

