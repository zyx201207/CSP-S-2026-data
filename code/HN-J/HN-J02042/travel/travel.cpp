#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int c1 = s2[0] + s2[1],c2 = s4[0] + s4[1];
	if(s1 == s3)
	{
		if(c1 == c2)
		{
			if(s2[2] <= 'C' && s4[2] <= 'C' || s2[2] > 'C' && s4[2] > 'C')
			{
				if(abs((s2[2] - 'A') - (s4[2] - 'A')) == 1)
				{
					cout << "1111" << endl;
				}
				else
				{
					cout << "1110" << endl;
				}
			}
			else
			{
				cout << "1100" << endl;
			}
		}
		else
		{
			cout << "1000" << endl;
		}
		
	}
	else
	{
		cout << "0000" << endl;
	}
	return 0;
}
