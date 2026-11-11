#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",strin);
	freopen("travel.out","w",strout);
	int c1,c2;
	char ss1[4],ss2[4];
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>ss1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>ss2[i];
	}
	if(c1==c2)
	{
		cout<<'1';
		if(ss1[1]==ss2[1] && ss1[2]==ss2[2])
		{
			cout<<'1';
			if(ss1[3]=='A' && ss2[3]=='B' || ss1[3]=='A' && ss2[3]=='C')
			{
				cout<<'1';
				if(ss1[3]=='A' && ss2[3]=='B')
				{
					cout<<'1';
				}
			}
			else if(ss1[3]=='B' && ss2[3]=='A' || ss1[3]=='B' && ss2[3]=='C')
			{
				cout<<'1'<<'1';;
			}
			else if(ss1[3]=='C' && ss2[3]=='B' || ss1[3]=='C' && ss2[3]=='A')
			{
				cout<<'1';
				if(ss1[3]=='C' && ss2[3]=='B')
				{
					cout<<'1';
				}
			}
			else if(ss1[3]=='D' && ss2[3]=='F' || ss1[3]=='F' && ss2[3]=='D')
			{
				cout<<'1'<<'1';
			}
			else
			{
				cout<<'0'<<'0';
			}
		}
		else
		{
			cout<<'0'<<'0'<<'0';
		}
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	return 0;
}
