#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool s=true;
	for(int i=0;i<2;i++)
	{
		if(a[i]!=c[i])
		{
			s=false;
		}
	}
	if(s)
	{
		cout<<1;
		for(int i=0;i<2;i++)
		{
			if(b[i]!=d[i])
			{
				s=false;
			}
		}
		if(s)
		{
			cout<<1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))
			{
				cout<<1;
				if(((b[2]+1)==d[2])||((d[2]+1)==b[2]))
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
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
}
