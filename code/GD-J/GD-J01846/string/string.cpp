#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s = "@";
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int len;
		char a;
		cin >> len >> a;
		for(int i = 1; i <= len; i++)s += a;
	}
	for(int i = 1; 2 * i <= s.size(); i++)
	{
		char l = s[i], r = s[s.size() - i];
		if(l != r)ans++;
	}
	cout << ans;
	return 0;
}
