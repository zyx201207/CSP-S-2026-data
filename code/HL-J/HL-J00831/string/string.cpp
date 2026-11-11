#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r");
	freopen("string.out", "w");
	string s;
	long long n;
	cin >> n;
	for (int i = 1; i <= n ;i++)
	{
		long long x;
		cin >> x;
		string a;
		cin >> a;
		for (int j = 1; j <= x; j++)
		{
			s.append(a);
		}
	}
	long long ans = 0;
	for (int i=1; i <= s.size()/2;i++)
	{
		if (s[i] != s[s.size()-i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}