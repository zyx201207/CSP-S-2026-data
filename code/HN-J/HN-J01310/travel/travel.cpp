#include<bits/stdc++.h>
using namespace std;
int ans1,ans2;
string num1,seat1,num2,seat2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag=false;
    cin>>num1>>seat1>>num2>>seat2;
    if(num1==num2)
    {
    	cout<<1;
    	flag=true;
	}
    else
    {
    	cout<<0;
    	flag=false;
	}
    ans1=(seat1[0]-'0')*10+(seat1[1]-'0');
    ans2=(seat2[0]-'0')*10+(seat2[1]-'0');
    if(ans1==ans2&&flag==true)
    {
    	cout<<1;
    	flag=true;
	}
    else 
	{
		cout<<0;
		flag=false;
	}  
    if((((seat1[2]>='A'&&seat1[2]<='C')&&(seat2[2]>='A'&&seat2[2]<='C'))||((seat1[2]>='D'&&seat1[2]<='F')&&(seat2[2]>='D'&&seat2[2]<='F')))&&flag==true)
    {
    	cout<<1;
    	flag=true;
	}
	else
	{
		cout<<0;
		flag=false;
	}
	if(flag==true)
	{
		if(((seat1[2]>='A'&&seat1[2]<='C')&&(seat2[2]>='A'&&seat2[2]<='C')))
		{
			if(abs(int(seat1[2])-int(seat2[2]))==1)
			    cout<<1;
			else
			    cout<<0;
		}
		if((seat1[2]>='D'&&seat1[2]<='F')&&(seat2[2]>='D'&&seat2[2]<='F'))
		{
			if(seat1[2]!=seat2[2])
			    cout<<1;
			else
			    cout<<0;
		}
	}
	else
	    cout<<0;
    return 0;
}
