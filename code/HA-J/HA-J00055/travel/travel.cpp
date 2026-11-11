#include <iostream>
#include <cstdio>
using namespace std;
string c1,s1,c2,s2;
bool f1, f2, f3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		f1 = 1;
	} 
	else
	{
		cout << 0;
	}
	if (s1[0] == s2[0] and s1[1] == s2[1] and f1 == 1)
	{
		cout << 1;
		f2 = 1;
	}
	else
	{
		cout << 0;
	}
	if (f2 == 1 and (s1[2] >= 'A' and s1[2] <= 'C' and s2[2] >= 'A' and s2[2] <= 'C'  or s1[2] >= 'D' and s1[2] <= 'E' and s2[2] >= 'D' and s2[2] <= 'E' ))
	{
		cout << 1;
		f3 = 1;
	}
	else
	{
		cout << 0;
	}
	if (f3 == 1 and (s1[2] + 1 == s2[2] or s1[2] - 1 == s2[2]))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
