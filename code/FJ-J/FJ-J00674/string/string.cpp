#include <bits/stdc++.h>
using namespace std;
long long n, a, l, ans;
string s, t;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> a >> t;
		l += a;
		while (a--)
		{
			s += t;
		}
	}
	for (int i = 0;i < l / 2;i++)
	{
		if (s[i] == s[l - i - 1])
		{
			continue;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
/*
卑鄙我去吧瞬间就爱上雷神
yellow and purple 小 fish

i 0 1 2 3 4
s a a b b b
*/

