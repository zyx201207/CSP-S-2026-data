#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	char f=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f=1;
		cout<<f;
	}	
	else 
	{
		f=0;
		cout<<f;
	}
	if(c1==c2 &&  s1[0]==s2[0] && s1[1]==s2[1])
	{
		f=1;
		cout<<f;
	} 
	else
	{
		f=0;
		cout<<f;
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && (s1[2]+s2[2])/2!='C')
	{
		f=1;
		cout<<f;
	}	
	else 
	{
		f=0;
		cout<<f;
	}
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && (s1[2]+s2[2])/2!='C' && (s1[2]+s2[2])%2==1)
	{
		f=1;
		cout<<f;
	}	
	else 
	{
		f=0;
		cout<<f;
	}
	return 0;
}
