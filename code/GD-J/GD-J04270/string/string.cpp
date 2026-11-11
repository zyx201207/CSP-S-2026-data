#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
char c;
string s;
bool huiwen (string x)
{
	for (int i = 0; i < x.size() / 2; i++)
	{
		if (x[i] != x[x.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		for (int i = 1; i <= n; i++)
		{
			s += c;
		}
	}
	if (huiwen(s))
	{
		cout << 0;
		return 0;
	}
	n = s.size();
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
