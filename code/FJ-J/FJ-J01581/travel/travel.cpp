#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,r1,r2;
	cin>>c1>>c2>>r1>>r2;
	if(c1[0]==r1[0] && c1[1]==r1[1])
	{
		cout<<"1";
		if(c2[0]==r2[0] && c2[1]==r2[1])
		{
			cout<<"1";
			int x1,x2;
			if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C')
			{
				x1=1;
			}
			else
			{
				x1=2;
			}
			if(r2[2]=='A' || r2[2]=='B' || r2[2]=='C')
			{
				x2=1;
			}
			else
			{
				x2=2;
			}
			if(x1==x2)
			{
				cout<<"1";
				if(x1==2)
				{
					cout<<"1";
				}
				else if(abs((c2[2]-'A')-(r2[2]-'A'))==1)
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
