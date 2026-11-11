#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int R1,R2,X1,X2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin >> c1 >> s1 >> c2 >> s2;
	R1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	R2 = (s1[0] - '0') * 10 + (s1[1] - '0');
	X1 = (c2[0] - '0') * 10 + (c2[1] - '0');
	X2 = (s2[0] - '0') * 10 + (s2[1] - '0'); 
	if(R1 == X1)
	{
		cout << '1';
		if(R2 == X2)
		{
			cout << '1';
			if((('A' <= s1[2] && s1[2] <= 'C')&&('A' <= s2[2] && s2[2] <= 'C')) || (('F' == s1[2] && s2[2] == 'D')||('F' == s2[2] && s1[2] == 'D')))
			{
				cout << '1';
				if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
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
			}
		}
		else
		{
			cout << "000";
		}
	}
	else{
		cout << "0000"; 
	} 
	return 0;
}
