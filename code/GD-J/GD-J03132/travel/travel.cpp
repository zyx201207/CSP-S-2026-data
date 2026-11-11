#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,v1,v2;
	cin >> s1 >> v1 >> s2 >> v2;
	if (s1[0] != s2[0] || s1[1] != s2[1])
	{
		cout << "0000";
		return 0;
	}
	else
	{
		if (v1[0] == v2[0] && v1[1] == v2[1])
		{
			if (v1[2] == 'A' && v2[2] == 'B')
			{
				cout << "1111";
				return 0;
			}
			else if (v1[2] == 'B' && v2[2] == 'C')
			{
				cout << "1111";
				return 0;
			}
			if (v1[2] == 'A' && v2[2] == 'C')
			{
				cout << "1110";
				return 0;
			}
			else if (v1[2] == 'D' && v2[2] == 'F')
			{
				cout << "1111";
				return 0;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
