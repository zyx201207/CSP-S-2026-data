#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cheng1,cheng2;
	string sit1,sit2;
	cin>>cheng1>>sit1>>cheng2>>sit2;
	if(cheng1==cheng2)
	{
		cout<<"1";
		if(sit1[0]==sit2[0]&&sit1[1]==sit2[1])
		{
			cout<<"1";
			char a=sit1[2],b=sit2[2];
			if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))
			{
				cout<<"1";
				if((a=='A'&&b=='B')||(a=='B'&&(b=='A'||b=='C'))||(a=='C'&&b=='B')||(a=='D'||a=='F'))
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
