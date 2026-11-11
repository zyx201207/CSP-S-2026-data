#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2)//³µ 
	{
		cout<<"1";
		
	}
	else
	{
		cout<<"0";
	}
	if(s1==s2&&c1[1]==c2[1]&&c1[0]==c2[0])//ÅÅ 
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1==s2)
	{
		//(c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'&&c1[1]==c2[1]&&c1[0]==c2[0])||
		if((c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C'&&c1[1]==c2[1]&&c1[0]==c2[0])||(c1[2]>='D'&&c1[2]<='F'&&c2[2]>='D'&&c2[2]<='F'&&c1[1]==c2[1]&&c1[0]==c2[0]))//²à 
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
	if(c1[1]==c2[1]&&c1[0]==c2[0]&&( (c1[2]=='A'&&c2[2]=='B') || (c1[2]=='B'&&c2[2]=='C') || (c1[2]=='B'&&c2[2]=='A') || (c1[2]=='C'&&c2[2]=='B') || (c1[2]=='D'&&c2[2]=='F') || (c1[2]=='F'&&c2[2]=='D')))//ÏàÁÚ 
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}

	return 0;
}
