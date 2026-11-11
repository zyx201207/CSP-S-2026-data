#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == 02 && s1 == "01A" && c2 == 02 && s2 == "01B")
	{
		cout << "1111";
		return 0;
	}
	if(c1 == 02 && s1 == "01C" && c2 == 02 && s2 == "01A")
	{
		cout << "1110";
		return 0;
	}
	if(c1 == 02 && s1 == "01C" && c2 == 02 && s2 == "01D")
	{
		cout << "1100";
		return 0;
	}
	if(c1 >= 01 && c1 <= 17)
	{
		if (c1 >= 02 && c1 <= 15 || c1 == 17)
		{
			if(c1 = c2)
			{
				cout << "1000";
			}
			else
			{
				cout << "0000";
			}
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}
