#include<bits/stdc++.h>
using namespace std;
long long a1,a2,b1,b2;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if(c1 == 'F')c1 = 'E';
	if(c2 == 'F')c2 = 'E';
	if(a1 == a2)
	{
		cout << 1;
		if(b1 == b2)
		{
			cout << 1;
			if(c1 <= 'C' && c2 <= 'C' || c1 > 'C' && c2 > 'C')
			{
				cout << 1;
				if(abs(c1 - c2) == 1)
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
//100pts
