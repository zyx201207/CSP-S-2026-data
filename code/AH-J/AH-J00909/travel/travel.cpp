#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xc,rc;
	string xs,rs;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)
	{
		if(rs[0]==xs[0] && rs[1]==xs[1])
		{
			if(rs[2]=='A' || rs[2]=='B' || rs[2]=='C')
			{
				if(xs[2]=='A' || xs[2]=='B' || xs[2]=='C')
				{
					if(rs[2]=='A' && xs[2]=='B')
						cout<<"1111";
					else if(rs[2]=='B' && (xs[2]=='A' || xs[2]=='C'))
						cout<<"1111";
					else if(rs[2]=='C' && xs[2]=='B')
						cout<<"1111";
					else
						cout<<"1110";
				}
				else
					cout<<"1100";
			}
			else
			{
				if(xs[2]=='D' || xs[2]=='F')
					cout<<"1111";
				else
					cout<<"1100";
			}
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
}
