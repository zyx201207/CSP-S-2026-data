#include<bits/stdc++.h>
using namespace std;
string x1,x2,c1,c2;
long long f1=0,f2=0,f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>c1>>c2;
	
	if(x1==c1)
	{
		f=1;
		cout<<1;
	}
	else
	{
		f=0;
		cout<<0;
	}
	
	if(x2[0]==c2[0]&&x2[1]==c2[1])
	{
		if(f==1)
		{
			cout<<1;
			f1=1;
		}
		else
			cout<<0;
	}
	else
		cout<<0;
		
	if(x2[2]>='A'&&x2[2]<='C'&&c2[2]>='A'&&c2[2]<='C'&&f1==1&&f==1)
	{
		f2=1;
		cout<<1;
	}
	else if(x2[2]>='D'&&x2[2]<='F'&&c2[2]>='D'&&c2[2]<='F'&&f1==1&&f==1)
	{
		f2=1;
		cout<<1;
	}
	else
		cout<<0;
		
	if(f1==1&&f2==1&&f==1&&c2[2]-x2[2]==1)
		cout<<1;
	else if(f1==1&&f2==1&&f==1&&x2[2]-c2[2]==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
