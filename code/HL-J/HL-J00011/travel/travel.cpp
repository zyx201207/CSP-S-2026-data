#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		char aa,bb,cc,dd;
		aa=b[0];
		bb=b[1];
		cc=d[0];
		dd=d[1];
		if(aa==cc&&bb==dd)
		{
			cout<<"1";
			char x,y;
			x=b[2];
			y=d[2];
			if(x!='A'&&x!='B'&&x!='C'  &&  y!='A'&&y!='B'&&y!='C')
			{
				cout<<"11";
			}
			else if(x!='F'&&x!='D'&&y!='F'&&y!='D')
			{
				
				cout<<"1";
				if(x=='A'&&y=='C')
				{
					cout<<"0";
				}
				else if(y=='A'&&x=='C')
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
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