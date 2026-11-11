#include <bits/stdc++.h>
using namespace std;
string cg1,sg1,cg2,sg2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cg1 >> sg1 >> cg2 >> sg2;
	if (cg1[0] == cg2[0] && cg1[1] == cg2[1])
	{
		cout << "1";
		if (sg1[0] == sg2[0] && sg1[1] == sg2[1])
		{
			cout << "1";
			if (sg1[2] == 'A' && sg2[2] == 'B')
			{
				cout << "11";
			}
			else if (sg1[2] == 'A' && sg2[2] == 'C')
			{
				cout << "10";
			}
			else if (sg1[2] == 'B' && sg2[2] == 'A')
			{
				cout << "11";
			}
			else if (sg1[2] == 'B' && sg2[2] == 'C')
			{
				cout << "11";
			}
			else if (sg1[2] == 'C' && sg2[2] == 'A')
			{
				cout << "10";
			}
			else if (sg1[2] == 'C' && sg2[2] == 'B')
			{
				cout << "11";
			}
			else if (sg1[2] == 'D' && sg2[2] == 'F')
			{
				cout << "11";
			}
			else if (sg1[2] == 'F' && sg2[2] == 'D')
			{
				cout << "11";
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
