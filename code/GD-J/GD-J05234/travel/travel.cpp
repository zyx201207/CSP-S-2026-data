#include<bits/stdc++.h> 
using namespace std;
int c1,c3,x,y;
string c2,c4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	x=c2[2];
	y=c4[2];
	if(c1==c3)
	{
		cout<<"1";
		if(c2[1]==c4[1]&&c2[0]==c4[0])
		{
			cout<<"1";
			if(x<=67&&y<=67)
			{
				cout<<"1";
				if(max(x,y)-min(x,y)==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(x>67&&y>67)
			{
				cout<<"11";
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
