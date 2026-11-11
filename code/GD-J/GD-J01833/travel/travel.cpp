#include<bits/stdc++.h> 
using namespace std;
string c[4];
int c1,s1,c2,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	for(int i=1;i<=4;i++)
	{
		cin>>c1>>s1>>c2>>s2;
		c[1]=c1;
		c[2]=s1;
		c[3]=c2;
		c[4]=s2;
	}
    if(c[1]==01||c[3]==01||c[1]==16||c[3]==16)
    {
    	cout<<"0000";
	}
    if(c[1]==c[3])
    {
    	cout<<"1";
	}
	else
	{
		cout<<"0000";
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
	}
	if(s1[3]=="A")
	{
		if(s2[3]=="B")
		{
			cout<<"11";
		}
		else if(s2[3]=="C")
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
		}
	}
	if(s1[3]=="B")
	{
		if(s2[3]=="A")
		{
			cout<<"11";
		}
		else if(s2[3]=="C")
		{
			cout<<"11";
		}
		else
		{
			cout<<"00"
		}
	}
	if(s1[3]=="C")
	{
		if(s2[3]=="A")
		{
			cout<<"10";
		}
		else if(s2[3]=="B")
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
	}
	if(s1[3]=="D")
	{
		if(s2[3]=="F")
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
	}
	if(s1[3]=="F")
	{
		if(s2[3]=="D")
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
	}
	return 0;
}

