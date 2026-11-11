#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
    int n, a[105], sum = 0;
    char c[105];
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			s += c[i];
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = s.size(); j > 0; j--)
		{
			if (s[i] == s[j])
			{
				continue;
			}
			else
			{
				s[j] = s[i];
				sum++;
			}
		}
	}
	cout << sum / 2;
	return 0;
} 
