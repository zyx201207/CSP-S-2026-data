#include <bits/stdc++.h>
using namespace std;

long long n,x,len,sum;
string s,y;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		for (int j = 1; j <= x; j++)
		{
			s += y;
		}
	}
	len = s.length();
	for (long long i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
}
