#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;
	int cnt=0;
	string pd="";
	if(flag==1)
	{
	if(c1==c2) 
	{
		pd+='1';
	}
	else
	{
		flag=0;
		cnt++;
	}
	}
	else
	{
		cnt++;
	}
	
	
	
	
	
	string a="",b="";
	char c,d;
	for(int i=0;i<3;i++)
	{
		if(s1[i]<='9' && s1[i]>='0')
		{
			a=a+s1[i];
			b=b+s2[i];
		}
		if(s1[i]<='D' && s1[i]>='A')
		{
			c=s1[i];
			d=s2[i];
		}
	}
	
	
	
	if(flag==1)
	{
		if(a==b)
	{
		pd+='1';
	}
	else
	{
		flag=0;
		cnt++;
	}
	}
	else
	{
		cnt++;
	}
	
	
	
	
	if(flag==1)
	{
	if((c<='C' && c>='A') && (d>='A' && d<='C') )
	{
		pd+='1';
	}
	else if(((c<='F'&& c>='D') && (d>='D' && d<='F')) && (c!=d && c!='E'))
	{
		pd+='1';
	}
	else
	{
		flag=0;
		cnt++;
	}
	}
	else
	{
		cnt++;
	}
	
	
	
	if(flag==1)
	{
		if(c+1==d || c-1==d)
	{
		pd+='1';
	}
	else if(c+2==d || c-2==d)
	{
		flag=0;
		cnt++;
	}
	}
	else
	{
		cnt++;
	}
	for(int i=1;i<=cnt;i++)
	{
		pd+='0'; 
	}

	cout<<pd;
	return 0;
}
