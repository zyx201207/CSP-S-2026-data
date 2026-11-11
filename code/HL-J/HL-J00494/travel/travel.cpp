#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<1;
		if(b1.substr(0,2)==b2.substr(0,2))
		{
			cout<<1;
			if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')
			{
				if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')
				{
					cout<<1;
					if(abs(b1[2]-b2[2])<=1)
					{
						cout<<1;
						return 0;
					}
					else 
					{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			
			
			
			else{
				if(b2[2]=='D'||b2[2]=='F')
				{
					cout<<11;
					return 0;
				}
				else
				{
					cout<<"00";
					return 0;
				}
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}