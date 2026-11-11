#include <bits/stdc++.h>
using namespace std;

int n;
struct para
{
	int a, c;
}s[200005];

long long ans;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		char c;
		cin >> s[i].a >> c;
		s[i].c = c - 'a';
	}
	int p = 1, q = n, px = 0, qx = 0;
	while (p < q)
	{
		int pr = s[p].a - px, qr = s[q].a - qx;
		if (pr == qr)
		{
			if (s[p].c != s[q].c) ans += pr;
			p++;
			q--;
			px = 0;
			qx = 0;
		}
		else if (pr < qr)
		{
			if (s[p].c != s[q].c) ans += pr;
			p++;
			px = 0;
			qx += pr;
		}
		else
		{
			if (s[p].c != s[q].c) ans += qr;
			q--;
			qx = 0;
			px += qr;
		}
	}
	cout << ans;
	return 0;
}
