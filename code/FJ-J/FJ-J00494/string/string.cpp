#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		string a;
		cin >> x >> a;
		for (int i = 1; i <= x; i++)
		{
			s += a;
		}
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	int mid = 0;
	if (s.size() % 2 == 1)
	{
		mid = s.size() / 2 + 1;
		int l = mid - 1, r = mid + 1;
		for (int i = 1; i <= mid - 1; i++)
		{
			if (s[l - 1] == s[r - 1])
			{
				l--, r++;
			}
			else
			{
				ans++;
				l--, r++;
			}
		}
	}
	else
	{
		mid = s.size() / 2;
		int l = mid, r = mid + 1;
		for (int i = 1; i <= mid; i++)
		{
			if (s[l - 1] == s[r - 1])
			{
				l--, r++;
			}
			else
			{
				ans++;
				l--, r++;
			}
		}
	}
	cout << ans;
	return 0;
}
