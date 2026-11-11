#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
		string x="",y="";
		x+=s1[0];
		x+=s1[1];
		y+=s2[0];
		y+=s2[1];
		if (x!=y)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<1;
			string m="",n="";
			m+=s1[2];
			n+=s2[2];
			if ((m=="A" && n=="D") || (m=="A" && n=="F") || (m=="B" && n=="D") || (m=="B" && n=="F") || (m=="C" && n=="F") || (m=="C" && n=="D"))
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<1;
				if ((m=="A" && n=="B") || (m=="B" && n=="A") || (m=="B" && n=="C") || (m=="C" && n=="B") || (m=="D" && n=="F") || (m=="F" && n=="D"))
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
