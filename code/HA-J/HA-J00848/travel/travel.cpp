#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);                                                                                                                              
	freopen("travel.out","w",stdout);
	char ans1[10];
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans1[0]='1';
	}
	else
		ans1[0]='0';
	if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)
	{
		ans1[1]='1';
	}
	else
		ans1[1]='0';
	if(s1[2]<='C'&&s2[2]<='C'&&s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)
	{
		ans1[2]='1';
	}
	else 
		ans1[2]='0';
	if(s1[2]>='D'&&s2[2]>='D'&&s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)
	{
		ans1[2]='1';
	}
	
	if(s1[2]+s2[2]!='C'+'D'&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)&&s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)
	{
		ans1[3]='1';
	}
	else
		ans1[3]='0';
	cout<<ans1;
	
	return 0;
} 
