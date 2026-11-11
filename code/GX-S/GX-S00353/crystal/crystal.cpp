#include<algorithm>
#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
using namespace std;
int n;
long long m, a[500001], qzh[500001];
bool llp (long long b, long long c)
{
	return b < c;
}
bool ch (int x)
{
	for (int i = 1; i <= n - x + 1; i++)
	{
		long long xx = i - 1;
		if (qzh[i + x - 1] - qzh[i] - (a[i + x - 1] - a[i]) * xx <= m)
		{
			return true;
		}
	}
	return false;
}
inline long long read ()
{
	long long x = 0, f = 1;
	char c = getchar ();
	while (c < '0' || c > '9')
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar ();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar ();
	}
	return x * f;
}
int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	n = read ();
	m = read ();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read ();
	}
	sort (a + 1, a + n + 1, llp);
	for (int i = 2; i <= n; i++)
	{
		long long x = i - 1;
		qzh[i] = qzh[i - 1] + (a[i] - a[i - 1]) * x;
	}
	int l = 1, r = n;
	while (l < r)
	{
		int mid = ((l + r) >> 1) + 1;
		if (ch (mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	
	return 0;
}
