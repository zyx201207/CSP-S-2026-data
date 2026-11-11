#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string n1,n2,n3,n4;
    bool f=0;
    cin>>n1>>n2>>n3>>n4;
     if(n1==n3)
    {
    	cout<<1;
    	f=1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	
	
	if(n2[0]==n4[0]&&n2[1]==n4[1]&&f==1)
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	
	
    if(n2[2]<='C'&&n4[2]<='C'&&f==1)
	{
		cout<<1;
		f=1;
	}
	else if(n2[2]>'C'&&n4[2]>'C'&&f==1)
	{
		cout<<1;
		f=1;
	}
	else
	{
		cout<<0;
		f=0;
	}
	
	
	if(n2[2]==(n4[2]+1)||n2[2]==(n4[2]-1)&&f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    return 0;
}