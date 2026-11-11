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
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))
			{
				cout<<1;
				if(b[2]>'C')
				{
					cout<<1;
				}
				else if(abs(int(b[2])-int(d[2]))==1)
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
				cout<<"00";
			}
		}
		if(b[0]!=d[0]||b[1]!=d[1])
		{
			cout<<"000";
		}
	}
	if(a!=c)
	{
		cout<<"0000";
	}
}
