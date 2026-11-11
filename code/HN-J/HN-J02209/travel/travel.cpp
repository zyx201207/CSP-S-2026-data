#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ss1,ss2,lzn;//lzn：关我何事？！ 
char sss1,sss2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		lzn=lzn+'1';
		ss1="";
		ss2="";
		for(int i=0;i<2;i++)
		{
			ss1=ss1+s1[i];
			ss2=ss2+s2[i];
		}
		sss1=s1[2];
		sss2=s2[2];
		if(ss1==ss2)
		{
			lzn=lzn+'1';
		}
		else
		{
			lzn=lzn+'0';
		}
		if((ss1==ss2)&&((sss1>='D'&&sss2>='D')||(sss1>='A'&&sss2>='A'&&sss1<='C'&&sss2<='C')))
		{
			lzn=lzn+'1';
		}
		else
		{
			lzn=lzn+'0';
		}
		int ssss1=int(sss1),ssss2=int(sss2);
		if((ss1==ss2)&&((sss1>='D'&&sss2>='D')||(sss1>='A'&&sss1<='C'&&sss2>='A'&&sss2<='C'&&abs(ssss1-ssss2)<=1)))
		{
			lzn=lzn+'1';
		}
		else
		{
			lzn=lzn+'0';
		}
	}
	else
	{
		lzn="0000";
	}
	cout<<lzn;
	return 0;
}
