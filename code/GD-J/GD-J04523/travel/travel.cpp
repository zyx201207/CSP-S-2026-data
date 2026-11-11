#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		string sa=s1.substr(0,2),sb=s2.substr(0,2);
		if(sa==sb)
		{
			cout<<"1";
			int sx=(int)(s1[2]-'A')/3,sy=(int)(s2[2]-'A')/3;
			if(sx==sy)
			{
				cout<<"1";
				if(abs((int)(s1[2]-s2[2]))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
