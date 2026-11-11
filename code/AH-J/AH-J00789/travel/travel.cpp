#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s=0;
	string a,b,c,d,Rp,Xp;
	char Rh,Xh;
	cin>>a>>b>>c>>d;
	Rh=b[2];
	Xh=d[2];
	for(int i=0;i<=1;i++)
	{
		Rp=Rp+b[i];
		Xp=Xp+d[i];
	}
	if(a==c)
	{
		s++;
		cout<<1;
		if(Rp==Xp)
		{
			s++;
			cout<<1;
		}
		if(s<2)
		{
			s++;
			cout<<0;
		}
		if(Rp==Xp)
		{
			if(Xh>='A'&&Xh<='C'&&Rh>='A'&&Rh<='C')
			{
				s++;
				cout<<1;
			}
			if(Xh>='D'&&Xh<='F'&&Rh>='D'&&Rh<='F')
			{
				s++;
				cout<<1;
			}
		}
		if(s<3)
		{
			s++;
			cout<<0;
		}
		if(Rp==Xp&&abs(Xh-Rh)==1)
		{
			if(Xh>='A'&&Xh<='C'&&Rh>='A'&&Rh<='C')
			{
				s++;
				cout<<1;
			}
			if(Xh>='D'&&Xh<='F'&&Rh>='D'&&Rh<='F')
			{
				s++;
				cout<<1;
			}
		}
		if(s<4)
		{
			s++;
			cout<<0;
		}
	}
	else cout<<"0000";
	return 0;
}
