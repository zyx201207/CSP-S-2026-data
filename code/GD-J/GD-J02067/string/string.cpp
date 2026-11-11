#include <bits/stdc++.h>
using namespace std;
int n, a[1000000], ans;
string s = "";
char c;
int st(string x)
{
	int l = x.length(); 
	for (int i = 0; i < l / 2; i++)
	{
		if (s[i] != s[l - i - 1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c;
		for (int j = 1; j <= a[i]; j++)
		{
			s = s + c;
		}
	}
	if (st(s))
	{
		cout << 0;
		return 0;
	}
	int l = 0, r = s.length() - 1;
	while (l <= r)
	{
		if (s[l] != s[r])
		{
			s[r] = s[l];
			ans++;
		}
		if (st(s))
		{
			break;
		}
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
