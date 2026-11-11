#include<bits/stdc++.h>
using namespace std;
string n,n1,m,m1,a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>m>>m1;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
		a=n1[0]+n1[1];
		b=m1[0]+m1[1];
		if(a!=b)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<1;
			a=n1[2];
			b=m1[2];
			if(a[0]>='A'&&a[0]<='C'&&b[0]>='A'&&b[0]<='C')
			{
				cout<<1;
				if(a=="A"&&b=="B")
				{
					cout<<1;
					return 0;
				}
				else if(a=="B"&&b=="A"||b=="C")
				{
					cout<<1;
					return 0;
				}
				else if(a=="C"&&b=="B")
				{
					cout<<1;
					return 0;
				}
				else
				cout<<0;
			}
			else if(a[0]>='D'&&a[0]<='F'&&b[0]>='D'&&b[0]<='F')
			{
				cout<<"11";
				return 0;
			}
			else
			cout<<"00";
		}
	}
}
