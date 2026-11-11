#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
	{
		cout << 1;
		if (s1.substr(0,2) == s2.substr(0,2))
		{
			cout << 1;
			if (((s1.substr(2,1) >= "A") && (s1.substr(2,1) <= "C")) && ((s2.substr(2,1) >= "A") && (s2.substr(2,1) <= "C")))
			{
				cout << 1;
				if ((s1.substr(2,1) == "A" && s2.substr(2,1) == "B") || (s1.substr(2,1) == "B" && s2.substr(2,1) == "A"))
				{
					cout << 1;
				}
				else if ((s1.substr(2,1) == "B" && s2.substr(2,1) == "C") || (s1.substr(2,1) == "C" && s2.substr(2,1) == "B"))
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else if ((s1.substr(2,1) >= "D" && s1.substr(2,1) <= "F") && (s2.substr(2,1) >= "D" && s2.substr(2,1) <= "F"))
			{
				cout << 1;
				if ((s1.substr(2,1) == "D" && s2.substr(2,1) == "F") || (s1.substr(2,1) == "F" && s2.substr(2,1) == "D"))
				{
					cout << 1;
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				cout << 0 << 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0;
		}
	}
	else
	{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
