#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] - '0'== c2[0] - '0' && c1[1] - '0' == c2[1] - '0')
	{
		cout << '1';
		if (s1[0] - '0' == s2[0] - '0' && s1[1] - '0' == s2[1] - '0')
		{
			cout << '1';
			if (((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) || ((s1[2] >= 'A' && s1[2] <= 'C')&&(s2[2] >= 'A' && s2[2] <= 'C')))
			{
				cout << '1';
				int a1 = s1[2] - 'A';
				int a2 = s2[2] - 'A';
				if (((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) || ((abs(a1 - a2) == 1) && ((s1[2] != 'C' && s2[2] != 'D') || (s1[2] != 'D' && s2[2] != 'C'))))
				{
					cout << '1';
				}
				else
				{
					cout << '0';
				}
			}
			else
			{
				cout << "00";
			}//判断是否在同一侧 
		}
		else
		{
			cout << "000";
		}//是否在同一排 
	}
	else
	{
		cout << "0000";
		return 0;
	} // 是否在同一节车厢 
	return 0;
}
