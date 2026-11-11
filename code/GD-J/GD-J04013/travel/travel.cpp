#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>> c2>>s2;
	if(c1[0]==c2[0] &&c1[1]==c2[1])
	{
		cout << 1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout << 1;
			if((s1[2]>='A'&&s1[2]<='C' && s2[2]>='A'&&s2[2]<='C') || (s1[2]>='D'&&s1[2]<='F' && s1[2]>='D'&&s1[2]<='F'))
			{
				cout << 1;
				int r = s1[2],x = s2[2];
				if(abs(r-x)==1)	cout << 1;
				else	cout << 0;
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
//	cout << s1 <<' '<<s2;
	return 0;
}
