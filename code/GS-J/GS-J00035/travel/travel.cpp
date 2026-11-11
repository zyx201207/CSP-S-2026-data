#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,s,x,b;
	cin>>r>>s>>x>>b;
	string a=" ";
	string c=" ";
	string e=" ";
	string f=" ";
	for(int i=1;i<=s.size();i++)
	{
		if(i>='0'&&i<='18')
		{
			a+=i;
		}
		if(i>='A'&&i<='F')
		{
			c+=i;
		}
	}
	for(int j=1;j<=b.size();j++)
	{
		if(j>='0'&&j<='18')
		{
			e+=j;
		}
		if(j>='A'&&j<='F')
		{
			f+=j;
		}
	}
	//char h=c;
	//char l=f;
	if(r==x)
	{
		cout<<1;	
	}
	else
	{
		cout<<0;
	}
	if(a==e)
	{
		cout<<1;
		
	}	
	else
	{
		cout<<0;
	}
	if( c== f)
	{
		cout<<11;
		/*if(h+1==f||h-1==f||f+1==h||f-1==h)
		{
			cout<<1;	
		}	
		else
		{
			cout<<0;
		}*/
	}
	else
	{
		cout<<00;
	}
	return 0;
}
