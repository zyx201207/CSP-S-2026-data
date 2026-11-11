#include<bits/stdc++.h>
using namespace std;
string rf,rs,xf,xs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rf>>rs>>xf>>xs;
	if(rf==xf)
	{
		cout<<"1";
		if(rs[0]==xs[0]&&rs[1]==xs[1])
		{
			cout<<"1";
			if(rs[2]<='C'&&xs[2]<='C')
			{
				cout<<"1";
				if((rs[2]=='A'&&xs[2]=='B')||(rs[2]=='B'&&xs[2]=='A')||(rs[2]=='B'&&xs[2]=='C')||(rs[2]=='C'&&xs[2]=='B'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(rs[2]>='D'&&xs[2]>='D')
			{
				cout<<"1";
				if((rs[2]=='D'&&xs[2]=='E')||(rs[2]=='E'&&xs[2]=='D'))
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
