#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[4];
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>c2>>s1>>s2;
if(c1==c2)
{
	a[0]=1;
}
for(int i=0;i<2;i++)
{
	if(s1[i]==s2[i]&&a[0]==1)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
}
if(a[1]==1&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s1[2]=='F')))&&a[0]==1)
{
	a[2]=1; 
}
else
{
	a[2]=0;
}
if(a[0]==1&&a[1]==1&&a[2]==1&&(s1[2]=='D'||s1[2]=='F'||s1[2]=='B'||s2[2]=='B'))
{
	a[3]==1;
}
else
{
	a[3]==0;
}
cout<<a[02]<<a[1]<<a[2]<<a[3];
return 0;
}
