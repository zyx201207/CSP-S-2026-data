#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	int n=b[0]-'0',m=d[0]-'0',l=b[1]-'0',r=d[1]-'0';
	int b2=b[2],d2=d[2];
	if(a==c)
	{
		cout<<1;
		if(n==m&&l==r)
		{
			cout<<1;
			if((b2=='A'&&d2=='B')||(b2=='A'&&d2=='C')||(b2=='B'&&d2=='A')||(b2=='B'&&d2=='C')||(b2=='C'&&d2=='A')||(b2=='C'&&d2=='B')||(b2=='D'&&d2=='E')||(b2=='E'&&d2=='D'))
			{
				cout<<1;
				if((b2=='A'&&d2=='B')||(b2=='B'&&d2=='A')||(b2=='B'&&d[2]=='C')||(b2=='C'&&d2=='B')||(b2=='D'&&d2=='E')||(b2=='E'&&d2=='D'))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
