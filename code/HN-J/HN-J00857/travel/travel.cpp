#include<bits/stdc++.h>
using namespace std;
int c1,c2,b1,b2,a1,a2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	b1=s1[2]-'A';
	b2=s2[2]-'A';
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2)
	{
		cout<<1;
		if(a1==a2)
		{
			cout<<1;
			if(b1>=0&&b1<=2&&b2>=0&&b2<=2)
			{
				cout<<1;
				if(b1-b2==1||b2-b1==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if((b1==3&&b2==5)||(b1==5&&b2==3)) 
			{
				cout<<1<<1;
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
