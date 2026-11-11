#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char st1,st2;
	cin >> c1 >> s1 >> st1 >> c2 >> s2 >> st2;
	bool a = 0,b = 0,c = 0,d = 0;
	if (c1 == c2)
	{
		a = 1;
		if (s1 == s2)
		{
			b = 1;
			if ((st1 < 'D' and st2 < 'D') or (st1 > 'C' and st2 > 'C'))
			{
				c = 1;
				if (abs(st1 - st2) == 1)
				{
					d = 1;
				}
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
