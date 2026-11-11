#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int f=1;
	int f1=0;
	int f2=0;
	int f3=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s3[i])
		{
			f=0;
			break;
		}
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])
	{
		f1=1;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])
	{
		if((s2[2]>='A'&&s2[2]<='C')&&(s4[2]>='A'&&s4[2]<='C'))
		{
			f2=1;
		}
		else if((s2[2]>='E'&&s2[2]<='F')&&(s4[2]>='E'&&s4[2]<='F'))
		{
			f2=1;
		}
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1])
	{
		if(abs(s2[2]-s4[2])==1)
		{
			if((s2[2]=='C'&&s4[2]=='D')||(s2[2]=='D'&&s4[2]=='C'))
			{
				f3=0;
			}
			else
		    	f3=1;
		}
	}
	cout<<f<<f1<<f2<<f3;
	return 0;
} 
