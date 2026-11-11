#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s = "";
	vector<long long> a(n);
	vector<char> b(n);
	vector<long long> c(n, 0)
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		for (long long j = 0; j < a[i]; j++)
		{
			s += b[i];
		}
	}
	string sa = s;
	reverse(s.begin(), s.end());
	if (s == sa)
	{
		cout << 0;
		return 0;
	}
	else
	{
	    long long cnt = 0;
		if (sa.size() % 2 == 0)
		{
			for (long long i = 0; i < sa.size() / 2; i++)
			{
				if (sa[i] == sa[sa.size() - 1 - i])
				{
					continue;
				}
				else
				{
					cnt++;
				}
			}
			cout << cnt;
			return 0;
		}
		else if (sa.size() % 2 == 1)
		{
			for (long long i = 0; i < sa.size() / 2; i++)
			{
				if (sa[i] == sa[sa.size() - 1 - i])
				{
					continue;
				}
				else
				{
					cnt++;
				}
			}
			cout << cnt;
			return 0;
		}
	}
	return 0;
} 
