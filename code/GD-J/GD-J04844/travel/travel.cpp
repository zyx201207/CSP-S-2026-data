#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char k1=s1[2],k2=s2[2];
	char a1=s1[0],a2=s2[0];
	char b1=s1[1],b2=s2[1];
	string d1,d2;
	d1=a1+b1;
	d2=a2+b2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(d1!=d2)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(!(((k1=='C'&&k2=='D')||(k1=='D'&&k2=='C'))&&abs(int(k1)-int(k2))==1))
			{
				cout<<"1";
				if(abs(int(k1)-int(k2))==1)
				{
					if((k1=='C'&&k2=='D')||(k1=='D'&&k2=='C'))
					cout<<"0";
					else
					cout<<"1";
				}
				else
				cout<<"0";
			}
			else
			cout<<"00";
		}
	}
	return 0;
}
