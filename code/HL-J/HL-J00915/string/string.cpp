#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	string s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		for (int j = 1; j <= x; j++)
		{
			s += c;
		}
	}
	int sum = 0;
	for (int i = 0; i <= n / 2; i++)
	{
		if (s[i] != s[s.size() - 1]) sum++;
	}
	cout << sum;
	return 0;
}