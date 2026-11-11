#include<bits/stdc++.h>
#include<string>
using namespace std;
string a,b,c,d;
int main()
{
	freopen('travel.in','r',stdin);
	freopen('travel.out','w',stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(b[1]==d[1])
		{
			cout<<"1";
			if((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))
			{
				cout<<"1";
				if(d[2]=='B'||b[2]=='B')
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if((d[2]=='D'||d[2]=='E')&&(b[2]=='D'||b[2]=='E'))
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
	else if(a!=c)
	{
		cout<<"0000";
	}
} 
