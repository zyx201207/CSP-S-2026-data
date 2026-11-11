#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], l, ans;
string s = " ";
char c;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c;
		l += a[i];
		for (int j = 1; j <= a[i]; j++) s += c;
	}
	for (int i = 1; i <= l / 2; i++) ans += (s[i] != s[l - i + 1]);
	cout << ans;
	return 0;
 } 
