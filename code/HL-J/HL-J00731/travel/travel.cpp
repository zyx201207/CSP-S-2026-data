#include<bits/stdc++.h>
using namespeas std;

string c1,c2,r1,r2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>r1>>r2;
	if(c1==r1)
	{
		cout<<"1";
		if(c2[1]==r2[1]&&c2[2]==r2[2])
		{
			cout<<"1";
			if((c2[3]>='A'&&c2[3]<='C'&&r2[3]>='A'&&r2[3]<='C')||(c2[3]>='D'&&c2[3]<='E'&&r2[3]>='D'&&r2[3]<='E'))
			{
				cout<<"1";
				if((c2[3]=='A'&&r2[3]=='B')||(c2[3]=='B'&&r2[3]=='C')||(r2[3]=='A'&&c2[3]=='B')||(r2[3]=='B'&&c2[3]=='C')||(c2[3]=='D'&&r2[3]=='E')||(r2[3]=='D'&&c2[3]=='E'))
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