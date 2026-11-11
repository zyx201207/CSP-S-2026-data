#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s01;
	string s02;
	s01=s1[0]+s1[1];
	s02=s2[0]+s2[1];
	int d1=int(s1[2])-65;
	int d2=int(s2[2])-65;
	if(c1==c2)
	{
		cout<<"1";
		if(s01==s02)
		{
			cout<<"1";
			if((d1<=2&&d2<=2)||(d1>2&&d2>2))
			{
				cout<<"1";
				if(d1+1==d2||d1-1==d2)
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
