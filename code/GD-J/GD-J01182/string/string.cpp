#include <bits/stdc++.h>
using namespace std;
int n, a;
int main ()
{
	//freopen ("string.in", "r", stdin);
	//freopen ("string.out", "w", stdout);
	string s1, p, v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		char l;
		cin >> x >> l;
		for (int j = 0; j < x; j++)
	    {
	    	s1[j] = l;
		}
    }
    int m = s1.size(), y, h;
    if (m % 2 == 0)
    {
    	y = m / 2;
    	h = m / 2;
	}
	else
	{
		y = (m - 1) / 2;
		h = (m - 1) / 2;
	}
	
	for (int i = 0; i < y; i++)
	{
		p += s1[i];
	}
	for (int i = h; i > 0; i--)
	{
		v += s1[i];
	}
	if (p == v)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		if (p[i] != v[i])
		{
			a++;
		}
	}
	cout << a;
	return 0;
}
