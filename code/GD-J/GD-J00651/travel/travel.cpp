#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		int ddd=1;
		for(int i=0;i<b.size()-1;i++)
		{
			if(b[i]!=d[i])
			{
				ddd=0;
			}
		}
		if(ddd)
		{
			cout<<1;
			if(((b[b.size()-1]>='A'&&b[b.size()-1]<='C')&&(d[d.size()-1]>='A'&&d[d.size()-1]<='C'))||((b[b.size()-1]>='D'&&b[b.size()-1]<='F')&&(d[d.size()-1]>='D'&&d[d.size()-1]<='F')))
			{
				cout<<1;
				if(b[b.size()-1]==d[d.size()-1]+1||b[b.size()-1]==d[d.size()-1]-1)
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
	
	return 0;
}
