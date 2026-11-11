#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool flag=1;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else 
	{
		cout<<0;
		flag=0;
	}
	
	
	string a,b;
	a=s1.substr(0,2);
	b=s2.substr(0,2);
	if(a==b and flag==1) cout<<1;
	else 
	{
		cout<<0;
		flag=0;
	}
	
	
	char c=s1[2];
	char d=s2[2];
	if(flag==1)
	{
		if((c>='A' and c<='C' and d>='A' and d<='C')or (c=='D' and d=='F')or (d=='D' and c=='F'))
		{
			cout<<1;
		}
		else 
		{
		cout<<0;
		flag=0;
		}
	}
	else 
		{
		cout<<0;
		flag=0;
		}
	
	if(flag==1)
	{
		if(c+1==d)
		{
			cout<<1;
		}
		else 
		{
		cout<<0;
		flag=0;
		}
	}
	else 
		{
		cout<<0;
		flag=0;
		}
	return 0;
}
