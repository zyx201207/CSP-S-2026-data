#include <bits/stdc++.h>
using namespace std;

long long n, l = 0, num = 0;
string s;
bool j = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	vector<long long> a(n + 1);
	vector<char> c(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		while (a[i] > 0)
		{
			s += c[i];
			a[i]--;
		}
	}
	char b = c[1];
	for (int i = 2; i <= n; i++)
	{
		if (b != c[i])
		{
			j = 1;
		}
	}
	if (j == 0)
	{
		cout << 0;
		return 0;
	}
	l = s.size();
	if (l % 2 == 1)
	{
		for (int i = 0; i < (l / 2) + 1; i++)
		{
			if (s[i] != s[l - i])
			{
				num++;
			}
		}
	}
	else
	{
		for (int i = 0; i < l / 2; i++)
		{
			if (s[i] != s[l - i])
			{
				num++;
			}
		}
	}
	cout << num;
	return 0;
}
