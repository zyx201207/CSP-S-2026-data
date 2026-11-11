#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s11,s22;
int t,l=0,k=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		s11+=s1[i];
		s22+=s2[i];
	}
	
	
	if(c1==c2)
	{
		printf("1");
	}
	else
	{
		printf("0000");
		return 0;
	}
	
	
	if(s11==s22)
	{
		t=1;
		printf("1");
	}
	else
	{
		printf("0");
		t=0;
	}
	
	
	if(t==0)
	{
		t=0;
		printf("0");
	}
	else if(s1[2]<'D'&&s2[2]<'D' || s1[2]>='D'&&s1[2]>='D')
	{
		t=1;
		printf("1");
	}
	else
	{
		t=0;
		printf("0");
	}
	
	
	if(s1[2]=='F')
	{
		s1[2]='E';
	}
	if(s2[2]=='F')
	{
		s2[2]='E';
	}
	if(t==0)
	{
		printf("0");
	}
	else if(t && s1[2]-1==s2[2]||s1[2]+1==s2[2])
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	return 0;
} 
