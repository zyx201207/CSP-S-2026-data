#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel2.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		cout << 1;
		if(s1[1]==s2[1]&&s1[0]==s2[0])
		{
			cout << 1;
			char a1 = s1[2]+'0';
			char a2 = s2[2]+'0';
			if(((a1<=115)&&(a2 <= 115))||((a1==116||a1==117)&&(a2 == 116||a2==117)))
			{
				cout << 1;
				if(a1-a2==1||a2-a1==1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << 0 << 0;
			}
		}
		else
		{
			cout << 0<<0<<0;
		}
	}
	else
	{
		cout << 0<<0<<0<<0;
	}
	return 0;
}
