#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
string c1, s1, c2, s2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	IOS;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		if(s1.substr(0, 2) == s2.substr(0, 2))
		{
			if(s1[2] >= 'A' && s1[2] <= 'C')
			{
				if(s2[2] >= 'A' && s2[2] <= 'C')
				{
					if(abs(s1[2] - s2[2]) == 1)
						cout << "1111\n";
					else
						cout << "1110\n";
				}
				else
					cout << "1100\n";
			}
			else if(s1[2] >= 'D' && s1[2] <= 'F')
			{
				if(s2[2] >= 'D' && s2[2] <= 'F')
				{
					if(abs(s1[2] - s2[2]) == 1)
						cout << "1111\n";
					else
						cout << "1110\n";
				}
				else
					cout << "1100\n";
			}	
		}
		else
			cout << "1000\n";
	}
	else
		cout << "0000\n";
	return 0;
}
