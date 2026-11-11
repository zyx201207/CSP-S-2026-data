#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long sum=0;
	string s;
	cin >> n;
	while (n--)
	{
		int a;
		char c;
		cin >> a >> c;
		while (a--)
		{
			s += c;
		}
	}
	for (int i = 0; i <= s.size()/2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
