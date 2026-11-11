#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,d1,d2;
	cin>>c1>>c2>>d1>>d2;
	c2=" "+c2;
	d2=" "+d2;
	char x=c2[3],y=d2[3];
	if(c1!=d1)
	{
		cout<<"0000"<<endl;
		return 0; 
	}
	else
	{
		cout<<"1";
	}
	if(c2[1]==d2[1] && c2[2]==d2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(abs((int)x-(int)y)<=2 && (!(x=='C' && y=='D') && !(x=='D' && y=='C')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs((int)x-(int)y)==1 && (!(x=='C' && y=='D') && !(x=='D' && y=='C')))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	cout<<endl;
	return 0;
}
