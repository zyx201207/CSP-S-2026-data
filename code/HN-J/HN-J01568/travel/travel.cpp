#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc)
	{
		cout<<1;
		if(rz[0]==xz[0]&&rz[1]==xz[1])
		{
			cout<<1;
			if(rz[2]=='A'||rz[2]=='B'||rz[2]=='C'&&xz[2]=='A'||xz[2]=='B'||xz[2]=='C')
			{
				cout<<1;
				if(rz[2]+1==xz[2]||rz[2]-1==xz[2])
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(rz[2]=='F'||rz[2]=='D'&&xz[2]=='F'||xz[2]=='D')
			{
				cout<<11;
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
