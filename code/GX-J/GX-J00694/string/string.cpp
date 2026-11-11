#include <bits/stdc++.h>
using namespace std;
int n, a, ans;
string c, s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		for (int j = 1; j <= a; j++)
		{
			s += c;
		}
	}
	int r = 0, l = s.size();
	while (r < l)
	{
		if (s[r] != s[l])
		{
			ans++;
		}
		r++;
		l--;
	}
	cout << ans;
	return 0;
}
