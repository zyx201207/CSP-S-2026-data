#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)
	{
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			if('A' <= s1[2] <= 'C'&& 'A' <= s1[2] <= 'C' || 'D' <= s1[2] <= 'F'&&'D' <= s1[2] <= 'F')
			{
				if(s1[2]-s2[2] == 1 || s2[2]-s1[2] ==1)
				{
					cout << "1111";
					return 0;
				}
				else
				{
					cout << "1110";
					return 0;
				}
			}
			else
			{
				cout << "1100";
				return 0;
			}
		}
		else
		{
			cout << "1000";
			return 0;
		}
	}
	cout << "0000";
	return 0;
}
