#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}	
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int s1_=0,s2_=0;
	s1_=(s1[0]-'0')*10+(s1[1]-'0');
	s2_=(s2[0]-'0')*10+(s2[1]-'0');
	
	if(s1_==s2_)
	{
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
	char sss1=s1[2],sss2=s2[2];
	if(s1_==s2_)
	{
		if(sss1>='A'&&sss1<='C'&&sss2>='A'&&sss2<='C')
		{
			cout<<1;
		}
		else if(sss1>='D'&&sss1<='F'&&sss2>='D'&&sss2<='F')
		{
			cout<<1;
		}
		else{
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	
	if(s1_==s2_)
	{
		if(sss1>='A'&&sss1<='C'&&sss2>='A'&&sss2<='C')
		{
			if((sss1!='A'&&sss2!='C')&&(sss1!='C'&&sss2!='A'))
			{
				cout<<1;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else if(sss1>='D'&&sss1<='F'&&sss2>='D'&&sss2<='F')
		{
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
