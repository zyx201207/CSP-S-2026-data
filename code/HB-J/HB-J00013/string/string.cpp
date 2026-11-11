#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int res = 0;
	char x = getchar_unlocked();
	while (x > '9' || x < '0') x = getchar_unlocked();
	while (x >= '0' && x <= '9')
	{
		(res *= 10) += (x - '0');
		x = getchar_unlocked();
	}
	return res;
}
int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	int n = read();
	string str;
	for (int i = 1; i <= n; i++)
	{
		int a = read();
		char c = getchar_unlocked();
		while (a--)
			str  = str + c;
	}
	size_t len = str.length();
	str = " " + str;
	long long ans = 0;
	for (size_t i = 1; i + i <= len; i++)
		if (str[i] != str[len - i + 1])
			ans++;
	printf("%lld\n", ans);
	return 0;
}
