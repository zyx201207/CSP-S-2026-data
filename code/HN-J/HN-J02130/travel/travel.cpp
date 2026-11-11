#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char x = 0,y = 0;
	x = b[2];
	y = d[2];
	if(a[0]==c[0] && a[1]==c[1])
	{
		cout<<"1";
		if(b[0]==d[0] && b[1]==d[1])
		{
			cout<<"1";
			if(x>='A' && x<='C' && y>='A' && y<='C' || x>='D' && x<='F' && y>='D' && y<='F' && x!='E' && y!='E')
			{
				cout<<"1";
				if(x-y==1 || y-x==1)
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
