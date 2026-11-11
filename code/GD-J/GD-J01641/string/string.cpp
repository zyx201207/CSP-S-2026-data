#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[200005]; 
char c[200005];

signed main()
{
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	int n;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for(int i = 1; i <= a[i]; i++)
		{
			s += c[i];
		}
	}
	int ans = 0;
	for(int i = 0; i < s.size() / 2; i++)
	{
		ans += (s[i] != s[s.size() - i - 1]);
	}
	cout << ans;
	return 0;
}
