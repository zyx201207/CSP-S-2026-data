#include <bits/stdc++.h>
using namespace std;
bool flag=true;
bool flag1=true;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag1=false;
		
	}
	if(flag1==false)
	{
		cout<<0;
	}
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
				flag=false;
			}
		}
		else
		{
			cout<<0<<0;
			flag=false;
		}
		
	}
	
	
	if(flag==false||flag1==false)
	{
		cout<<0;
	}
	else
	{
		if(max(s1[2],s2[2])-min(s1[2],s2[2])==1)
		{
			cout<<1;
		}
	}

}
