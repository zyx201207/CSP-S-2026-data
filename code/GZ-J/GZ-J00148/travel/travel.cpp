//GZ-J00148，任润淏，贵阳市第三实验中学
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s, s1;
	string c, c1;
	cin>>c>>s>>c1>>s1;
	if(c==c1)
	{
		cout<<1;
		if(s[0]==s1[0] && s[1]==s1[1])
		{
			cout<<1;
			if((s[2]-'A'<3 && s1[2]-'A'<3)||(s[2]-'A'>2 && s1[2]-'A'>2))
			{
				cout<<1;
				if((abs(s[2]-s1[2])==1 && (s[2]-'A'<2 || s1[2]-'A'<2))||(s[2]-'A'>2 && s1[2]-'A'>2))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<00;
			}
		}
		else
		{
			cout<<000;
		}
	}
	else
	{
		cout<<0000;
	}
	return 0;
} 
