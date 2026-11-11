#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=false;
bool fl=false;
long long cnt=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cnt++;
		cout<<"1";
	}
	else
	{
		fl=true;
		cout<<"0";
	}
	if(fl==true)
	{
		for(int i=1;i<=3-cnt;i++)
		cout<<"0";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cnt++;
		cout<<"1";
	}
	else
	{
		fl=true;
		cout<<"0";
	}
	if(fl==true)
	{
		for(int i=1;i<=3-cnt;i++)
		cout<<"0";
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')
	{
		cout<<"1";
		flag=true;
		if(abs(s1[2]-s2[2])==1)
		{
			cout<<"1";
		}
		else
    	{
	    	cout<<"0";
    	}
	}
	else
	{
		cout<<"0";
	}
	if(flag==false)
	{
		cout<<"0";
	}
	return 0;
} 

