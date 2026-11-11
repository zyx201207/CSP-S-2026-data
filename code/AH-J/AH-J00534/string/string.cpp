#include <bits/stdc++.h>
using namespace std;
int n, t;
long long cnt;
char a;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> t;
		cin >> a;
		for (int j = 1 ; j <= t ; j++)
		{
			s += a;
		}
	}
	for (int i = 0 ; i < floor(int(s.size())) / 2 ; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
