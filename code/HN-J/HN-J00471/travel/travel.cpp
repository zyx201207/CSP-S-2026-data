#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	//frepoen("travel.in","r",stdin);
	//frepoen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		cout << "1";
		if(s1[1] = s2[1])
		{
			cout <<"1";
			if(s1 > "C" && s2 > "C")
			{
				cout << "11";
			}
			else if(s1 <= "C" && s2 <= "C")
			{
				cout << "1";
				if((s1 < "B" && s2 > "B") || (s1 > "B" s2 < "B"))
				{
					cout << "0";
				}
				else
				{
					cout << "1";
				}
			}
			else
			{
				cout <<"00";
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
