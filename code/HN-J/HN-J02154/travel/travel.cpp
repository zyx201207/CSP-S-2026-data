#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string che1,zuo1,che2,zuo2;
	cin >> che1 >> zuo1 >> che2 >> zuo2;
	if(che1 == che2) 
	{
	    cout << 1; 
		if(zuo1[0] == zuo2[0] && zuo1[1] == zuo2[1])
		{
			cout << 1;
			if(zuo1[2] == 'A' && zuo2[2] == 'B' || zuo1[2] == 'B' && zuo2[2] == 'A' || zuo1[2] == 'A' && zuo2[2] == 'C' || zuo1[2] == 'C' && zuo2[2] == 'A' || zuo1[2] == 'C' && zuo2[2] == 'B' || zuo1[2] == 'B' && zuo2[2] == 'C' || zuo1[2] == 'D' && zuo2[2] == 'F' || zuo1[2] == 'F' && zuo2[2] == 'D') 
			{
				cout << 1;
				if(zuo1[2] == 'A' && zuo2[2] == 'B' || zuo1[2] == 'B' && zuo2[2] == 'A' || zuo1[2] == 'C' && zuo2[2] == 'B' || zuo1[2] == 'B' && zuo2[2] == 'C' || zuo1[2] == 'D' && zuo2[2] == 'F' || zuo1[2] == 'F' && zuo2[2] == 'D')
				{
					cout << 1;
				}
				else cout << 0;
			}
			else 
			{
				cout << "00";
				return 0;
			}
		}
		else 
		{
			cout << "000";
			return 0;
		}
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
