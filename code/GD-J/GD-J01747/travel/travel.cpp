#include<bits/stdc++.h>
using namespace std;
int c[1000];
int b[9];
int d[1000];
int cnt=0;
int dnt=0;
int cc=0,dd=0;
int mian()
{
	freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2,s3,s4;
cin>>s1>>s2>>s3>>s4;
if(s1==s3)
{
	b[1]=1;
}
for(int i=1;i<=s2.size();i++)
{
	if(s2[i]>='0'&&s2[i]<='9')
	{
		cc+=s2[i]-'0';
	}
	if(s4[i]>='A'&&s2[i]<='Z')
	{
		cnt=s2[i]-'0';
	}
}
for(int i=1;i<=s4.size();i++)
{
	if(s4[i]>='0'&&s4[i]<='9')
	{
		dd=s4[i]-'0';
	}
	if(s4[i]>='0'&&s4[i]<='9')
	{
		dnt=s4[i]-'0';
	}
}
if(cc==dd)
b[2]=1;
else b[2]=0;
if(b[1]==1||b[2]==1||cc!='D'||cc!='C'||dd!='C'||dd!='D')
b[3]=1;
else b[3]=0;
if(cc-dd==1&&dd-cc==1&&cc!='D'&&cc!='C'&&dd!='C'&&dd!='D')
b[4]=1;
else
b[4]=0;
for(int i=1;i<=4;i++)
{
	cout<<b[i];
}
   return 0;
}

