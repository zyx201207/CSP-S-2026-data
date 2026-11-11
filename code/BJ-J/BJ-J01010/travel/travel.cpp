#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int a = 1, b = 1, c = 1, d = 1;
string op = "ABCDF";
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
    {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		cout << a << b << c << d;
		return 0;
	}
    for (int i = 0; i < 2; ++i)
    {
		if (s1[i] != s2[i])
		{
			b = 0;
			c = 0;
			d = 0;
			cout << a << b << c << d;
			return 0;
		}
	}
    bool f1 = false, f2 = false;
    char st1 = '0', st2 = '0';
    for (int i = 0; i < 3; ++i)
    {
		if (s1[2] == op[i])
        {
            f1 = true;
            st1 = op[i];
        }
		if (s2[2] == op[i])
        {
            f2 = true;
            st2 = op[i];
        }
	}
	if (f1 != f2)
    {
        c = 0;
        d = 0;
        cout << a << b << c << d;
        return 0;
    }
    d = 0;
	for (int i = 3; i < 5; ++i)
    {
		if (s1[2] == op[i]) st1 = op[i];
		if (s2[2] == op[i]) st2 = op[i];
	}
    if (st1 == 'A' || st1 == 'B' || st1 == 'C')
    {
        if (st1 > st2 && st1 - st2 == 1) d = 1;
        else if (st1 < st2 && st2 - st1 == 1) d = 1;
    }
    else d = 1;
    cout << a << b << c << d;
    return 0;
}