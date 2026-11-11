#include<bits/stdc++.h>
using namespace std;
string a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	if(a[0]==a[2])
	{
		cout<<"1";
		if(a[1][0]==a[3][0]&&a[1][1]==a[3][1])
		{
			cout<<"1";
			if(a[1][2]-'A'==0||a[1][2]-'A'==1||a[1][2]-'A'==2)
			{
				if(a[3][2]-'A'==0||a[3][2]-'A'==1||a[3][2]-'A'==2)
				{
					cout<<"1";
					if(a[1][2]-a[3][2]==1||a[3][2]-a[1][2]==1)
					cout<<"1";
					else
					cout<<"0";
				}
				else
				cout<<"00";				
			}
			else
			if(a[3][2]=='D'||a[3][2]=='F')
			cout<<"11";
			else
			cout<<"00";
			
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000";
	return 0;
}
