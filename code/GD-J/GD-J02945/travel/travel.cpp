#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string c1, s1, c2, s2;
bool f1, f2, f3;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	char t1 = s1[2], t2 = s2[2];
	f1 = c1 == c2;
	f2 = s1.substr(0, 2) == s2.substr(0, 2);
	f3 = (t1 <= 'C' && t2 <= 'C') || (t1 >= 'D' && t2 >= 'D');
	if (f1)
	{
		cout << 1;
		if (f2)
		{
			cout << 1;
			if (f3)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			cout << 0 << 0;
		}
		int te1 = s1[1], te2 = s2[1];
		if ((f2 && (f3 && abs(t2 - t1) == 1))|| (t1 == t2 && abs(te2 - te1) == 1))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0 << endl;
	}
	
	return 0;
}
