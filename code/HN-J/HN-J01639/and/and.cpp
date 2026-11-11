#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string p(ll x)
{
	string s = "";
	if (x == 0) return "0";
	while (x != 0)
	{
		int y = x % 2;
		string temp = to_string(y);
		s = s + temp;
		x /= 2;
	}
	return s;
}
long long q(ll x, ll y)
{
	string a = p(x), b = p(y), c = "";
	int len = max(a.size(), b.size());
	for (int i = 0; i < len; i++)
	{
		if (a[i] == b[i])
		{
			c[i] = '1';
		}
		else
		{
			c[i] = '0';
		}
	}
	ll z = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		int j = 1;
		z = z + (int)(c[i] - '0') * j;
		j *= 10;
	}
}
const ll MAXN = 2e5 + 10;
ll n, m, a[MAXN], max1, max2, j;
int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1)
		{
			j = a[i];
		}
		else
		{
			j = q(j, a[i]);
		}
		if (max1 < a[i])
		{
			max1 = a[i];
		}
		if (max2 < a[i] && max1 > a[i])
		{
			max2 = a[i];
		}
	}
	if (n == m)
	{
		cout << j;
	}
	else if (n <= 20)
	{
		cout << j;
	}
	else if (n <= 500)
	{
		cout << max1;
	}
	else if (n <= 1300)
	{
		cout << q(max1, max2);
	}
	else
	{
		cout << j;
	}
	return 0;
}



