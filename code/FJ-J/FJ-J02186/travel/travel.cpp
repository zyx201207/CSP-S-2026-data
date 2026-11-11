#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{	
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			if((a2[2]=='A'&&(b2[2]=='B'||b2[2]=='C'))||(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))||(a2[2]=='C'&&(b2[2]=='A'||b2[2]=='B'))||(a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D'))
			{
				if((a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='D'&&b2[2]=='F'))
				{
					cout<<"1111"<<endl;
					return 0;
				}
				else
				{
					cout<<"1110"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"1100"<<endl;
			}
		}
		else
		{
			cout<<"1000"<<endl;
			return 0;
		}
	}	
		else
		{
			cout<<"0000"<<endl;
			return 0;
		}
}