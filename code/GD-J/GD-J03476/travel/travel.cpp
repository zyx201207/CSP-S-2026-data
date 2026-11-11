#include <iostream>
#include <cstdio> 
#include <cmath>
#define ll long long
using namespace std;
int x, y, a, b;
string s1, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> x >> s1 >> y >> s2;
	a = (s1[0]-48)*10+s1[1]-48;
	b = (s2[0]-48)*10+s2[1]-48;
	if (x == y)
	{
		cout << "1";
		if (a == b)
		{
			cout << "1";
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))
			{
				cout << "1";
				if (abs(s1[2]-s2[2]) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
