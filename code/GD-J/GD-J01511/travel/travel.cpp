#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int f1, f2;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	f1 = 10 * (s1[0] - '0') + (s1[1] - '0');
	f2 = 10 * (s2[0] - '0') + (s2[1] - '0');
	
	if(c1 == c2)
	{
		cout << 1;
		
		if(f1 == f2)
		{
			cout << 1;
			
			
			if((s1[2] < 'D') ^ (s2[2] < 'D'))
			{
				cout << "00";
			}
			else
			{
				cout << 1;
				
				if(abs(s1[2] - s2[2]) == 1)
				{
					cout << 1;
				}
				else
				{
					cout << "0"; 
				}
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
