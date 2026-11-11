#include <bits/stdc++.h>
using namespace std;
int n, a[200001], len, ans;
char c[200001];
string s, d;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		while (a[i]--) s += c[i];
	}
	len = s.size();
	d = s;
	reverse(d.begin(), d.end());
	for (int i = 0; i < len; i++)
	{
		if (s[i] != d[i]) ans++;
	}
	cout << ans / 2;
	return 0;
}
