#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin >> c >> s >> c1 >> s1;
	if(c[1]==c1[1])
	{
		cout << 1;
		if(s[1]==s1[1])
		{
			cout << 1;
			if((s[2]<='C'&&s1[2]<='C')||(s[2]>='D'&&s1[2]>='D')&&s[2]!=s1[2])
			{
				cout << 1;
				if(abs(s[2]-s1[2])==1)
				{
					cout << 1;
				}
				else
				{
					cout << "0";
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
	//解这道题时
	//不妨设小R为x 小X为y
}
