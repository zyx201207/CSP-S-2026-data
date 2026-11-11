#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string r1 = "", r2 = "";
	r1 += s1[0];
	r1 += s1[1];
	r2 += s2[0];
	r2 += s2[1];
	if (c1 != c2) cout << "0000";
	else
	{
		cout << 1;
		if (r1 != r2) cout << "000";
		else
		{
			cout << 1;
			int x1 = 0, x2 = 0;
			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') x1 = 1;
			else x1 = 2;
			if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') x2 = 1;
			else x2 = 2;
			if (x1 != x2) cout << "00";
			else
			{
				cout << 1;
				if (x1 == 2) cout << 1;
				else if (abs(s1[2]-s2[2]) == 1) cout << 1;
				else cout << 0;
			}
		}
	}
	return 0;
} 
