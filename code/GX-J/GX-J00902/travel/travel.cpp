#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int cnt;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
for(int i=0;i<c1.size();i++)
{
	if(c1[i]==c2[i])
	{
		cnt++;
	}
}
if(cnt==2)
{
	cout<<"1";
	if(s1[1]==s2[1]&&s1[0]==s2[0])
{
	cout<<"1";
	if(s1[2]<='C'&&s2[2]<='C')
	{
		cout<<"1";
		if(s1[2]==s2[2]+1||s2[2]==s1[2]+1)
		{	
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	if(s1[2]>='F'&&s2[2]>='F')
	{
		cout<<"1";
		if(s1[2]==s2[2]+1||s2[2]==s1[2]+1)
		{	
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if(s1[2]>='F'&&s2[2]<='C')
	{
		cout<<"00";
	}
	else if(s2[2]>='F'&&s1[2]<='C')
	{
		cout<<"00";
	}
}
else
{
	cout<<"000";
	
}
}
else
{
	cout<<"0000";
}
return 0;
}
