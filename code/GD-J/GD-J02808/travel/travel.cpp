#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char e,f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
    cin.tie();
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)
	{
		cout<<1;
		if(b==d)
		{
			cout<<1;
			if((e<='C'&&f<='C')||(e>'C'&&f>'C'))
			{
				cout<<1;
				if((e=='A'&&f=='C')||(f=='A'&&e=='C'))
				{
					cout<<0;
				}
				else
				{
					cout<<1;
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
