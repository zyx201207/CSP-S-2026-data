#include<bits/stdc++.h>
using namespace std;
int c,c2;
string t,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>t>>c2>>s2;
	if(c==c2)
	{
		cout<<1;
		if(t[0]==s2[0]&&t[1]==s2[1])
		{
			cout<<1;
			if((t[2]=='D'&&s2[2]=='F')||(t[2]=='F'&&s2[2]=='D')||(t[2]=='A'&&s2[2]=='B')||(t[2]=='B'&&s2[2]=='A')||(t[2]=='B'&&s2[2]=='C')||(t[2]=='C'&&s2[2]=='B'))
			{
				cout<<11;
			}
			else if((t[2]=='A'&&s2[2]=='C')||(t[2]=='C'&&s2[2]=='A'))
			{
				cout<<10;
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
