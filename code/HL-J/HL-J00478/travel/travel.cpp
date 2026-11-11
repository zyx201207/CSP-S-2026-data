#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a2,b,b2;
	char c,c2;
	cin>>a>>a2>>c>>b>>b2>>c2;
	if(a==b)
	{
		cout<<"1";
		if(a2==b2)
		{
			cout<<'1';
			if(((c=='A'||c=='B'||c=='C')&&(c2=='A'||c2=='B'||c2=='C'))||((c=='D'||c=='F')&&(c2=='D'||c2=='F')))
			{
				cout<<"1";
				if((c=='A'&&c2=='B')||(c=='B'&&c2=='A')||(c=='B'&&c2=='C')||(c=='C'&&c2=='D')||(c=='D'&&c2=='F')||(c=='F'&&c2=='D'))
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
