#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2)
	{
		ans="1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		ans+="1";
	}
	else
	{
		cout<<"1000";
		return 0; 
	} 
	char a=s1[2];
	char b=s2[2];
	
	if(((a>='A' && a<='C') && (b>='A' && b<='C')) || ((a>='D' && a<='F') && (b>='D' && b<='F')))
	{
		ans+="1";
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	
	if(abs(a-b)==1) 
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		cout<<"1110";
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
