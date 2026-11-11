#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int a=0,b=0,c=0,d=0,e=0,f=0;
	string a1,b1;
	string ans="";
	cin>>a>>a1>>b>>b1;
	c+=a1[0]-'0';
	c*=10;
	c+=a1[1]-'0';
	d+=b1[0]-'0';
	d*=10;
	d+=b1[1]-'0';
	e=a1[2]-'A'+1;
	f=b1[2]-'A'+1;
	if(a==b)
	{
		ans+='1';
		if(c==d)
	{
		ans+='1';
		if((e>3&&f>3)||(e<4&&f<4))
		{
			ans+='1';
		}
		else
		{
			ans+='0';
		}
		if((e+f)!=7&&((e-f)==1||(e-f)==-1))
		{
			ans+='1';
		}
		else
		{
			ans+='0';
		}
	}
	else
	{
		ans+="000";
	}
	}
	else
	{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}
