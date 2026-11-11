#include<bits/stdc++.h>
using namespace std;
string s,s1,a,a1;
int f;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s>>s1>>a>>a1;
	if(s==a)
	{
		cout<<1;
		f++;
	}	
	else
	{
		cout<<0;
	}
	if(s1[0]==a1[0]&&s1[1]==a1[1])
	{
		if(f==1)
		{
			cout<<1;
			f++;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if((s1[0]==a1[0]&&s1[1]==a1[1])&&((s1[2]<='C'&&a1[2]<='C')||(s1[2]>'C'&&a1[2]>'C')))
	{
		if(f==2)
		{
			cout<<1;
			f++;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if((s1[2]=='A'&&a1[2]=='B')||(s1[2]=='B'&&a1[2]=='A'))
	{
		if(f==3)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if((s1[2]=='B'&&a1[2]=='C')||(s1[2]=='C'&&a1[2]=='B'))
	{
		if(f==3)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if((s1[2]=='D'&&a1[2]=='F')||(s1[2]=='F'&&a1[2]=='D'))
	{
		if(f==3)
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
		cout<<0;
	}
	
	
	
	
	return 0;
}
//02 01A 02 01B
//02 01C 02 01A
//02 01C 02 01D
//02 02B 02 01A
//02 01A 03 01A

