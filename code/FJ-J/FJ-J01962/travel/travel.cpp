#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2)
	{
		cout << 0 << 0 << 0 << 0 << endl;
		return 0;
	}
	else
	{
		cout << 1;
		if((s1[0]+s1[1])==(s2[0]+s2[1]))
		{
			cout << 1;
			if(((s1[2]>=65&&s1[2]<=67)&&(s2[2]>=65&&s2[2]<=67))||((s1[2]>=68&&s1[2]<=70)&&(s2[2]>=68&&s2[2]<=70)))
			{
				cout << 1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))
				{
					cout << 1 << endl;
					return 0;
				}
				else
				{
					cout << 0 << endl;
					return 0;
				}
			}
			else
			{
				cout << 0 << 0;
				return 0;
			}
		}
		else
		{
			cout << 0 << 0 << 0 << endl;
			return 0;
		}
	}
}
