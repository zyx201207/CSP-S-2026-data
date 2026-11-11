#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int a[1000];
int b[1000];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[(int)'A'] = a[(int)'B'] = a[(int)'C'] = 1;
	a[(int)'D'] = a[(int)'F'] = 0;
	b[(int)'A'] = 1;
	b[(int)'B'] = 2;
	b[(int)'C'] = 3;
	b[(int)'D'] = 4;
	b[(int)'F'] = 5;
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) cout << "0000";
	else
	{
		if (s1[0] != s2[0] || s1[1] != s2[1])
		{
			cout << "1000";
		}
		else
		{
			if (a[s1[2]] != a[s2[2]])
			{
				cout << "1100";
			}
			else
			{
				if (abs(b[s1[2]] - b[s2[2]]) != 1) cout << "1110";
				else cout << "1111";
			}
		}
	}
	return 0;
}
