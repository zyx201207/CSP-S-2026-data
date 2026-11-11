#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(a==c)
	{
		cout<<"1";
		f++;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			f++;
			if((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(d[2]=='A'&&b[2]=='B')||(d[2]=='A'&&b[2]=='C')||(d[2]=='B'&&b[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
			{
				cout<<"1";
				f++;
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
				{
					cout<<"1";
					f++;
				}
				else
				{
					for(int i=1;i<=4-f;i++) cout<<"0";
				}
			}
			else
			{
				for(int i=1;i<=4-f;i++) cout<<"0";
			}
		}
		else
		{
			for(int i=1;i<=4-f;i++) cout<<"0";
		}
	}
	else
	{
		for(int i=1;i<=4-f;i++) cout<<"0";
	}
	return 0;
}
