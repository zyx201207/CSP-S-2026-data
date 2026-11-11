#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int a1,b1,a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	a1=c1[0]-'0';
	a2=c1[1]-'0';
	b1=c3[0]-'0';
	b2=c3[1]-'0';
	if (a1==b1&&a2==b2)
	{
		cout<<"1";
		a1=c2[0]-'0';
		a2=c2[1]-'0';
		b1=c4[0]-'0';
		b2=c4[1]-'0';
		if (a1==b1&&a2==b2)
		{
			cout<<"1";
			char x=c2[2];
			char y=c4[2];
			if (x-'A'<=2&&y-'A'<=2||x-'A'>=3&&y-'A'>=3)
			{
				cout<<"1";
				if (abs((x-'A')-(y-'A'))==1)
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
}
