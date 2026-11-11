#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	if(c1[0]-'0'==c2[0]-'0' && c1[1]-'0'==c2[1]-'0')
	{
		cout<<1;
		if(s1[0]-'0'==s2[0]-'0' && s1[1]-'0'==s2[1]-'0')
		{
		cout<<1;
		if(s1[2]<='c' && s2[2]<='c' || s1[2]>='d' && s2[2]>='d')
		{
		cout<<1;
		if(s1[2]-'0'==s2[2]-'0'+1 && s1[2]<='c' && s2[2]<='c' || s1[2]-'0'==s2[2]-'0'-1 && s1[2]<='c' && s2[2]<='c' || s1[2]=='d' && s2[2]=='f' || s1[2]=='f' && s2[2]=='d')
		cout<<1;
		else
		cout<<0;
	}
		else
		cout<<00;	
	}
		else
		{
			cout<<000;
		}
		
	}
	else
		cout<<0000;
	return 0;
 } 
