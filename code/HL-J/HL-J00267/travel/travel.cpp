#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>s1>>s2>>s3>>s4;
	int l1=s1.size();
	int l2=s2.size();
	int l3=s3.size();
	int l4=s4.size();
	if(s1[1]==s3[1]) f1=1;
	if(s2[1]==s4[1]&&f1==1) f2=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')
		{
			if(f1==1&&f2==1) f3=1;
		}
	}
	else
	{
		if(s4[2]=='D'||s4[2]=='F')
		{
			if(f1==1&&f2==1) f3=1;
		}
	}
	
	
	
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')
		{
			if(f1==1&&f2==1&&f3==1)
			{
				if(int(char(s2[2])+1)==char(s4[2])||int(char(s2[2])-1)==char(s4[2])) f4=1;
			}
		}
	}
	else
	{
		if(s4[2]=='D'||s4[2]=='F')
		{
			if(f1==1&&f2==1&&f3==1)
			{
				if(int(char(s2[2])+1)==char(s4[2])||int(char(s2[2])-1)==char(s4[2])) f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
