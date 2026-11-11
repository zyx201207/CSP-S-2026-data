#include<bits/stdc++.h>
using namespace std;
int ans1,ans2,ans3,ans4;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans1=1;
	}
	else
	{
		ans1=0;
		ans2=0;
		ans3=0;
		ans4=0;
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans2=1;
	}
	else
	{
		ans2=0;
		ans3=0;
		ans4=0;
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C')
	{
		ans3=1;
	}
	else if(s1[2]>='D'&&s2[2]>='D')
	{
		ans3=1;
	}
	else
	{
		ans3=0;
		ans4=0;
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
	if(s2[2]+1==s1[2])
	{
		ans4=1;
	}
	if(s1[2]+1==s2[2])
	{
		ans4=1;
	}
	if(s1[2]=='C'&&s2[2]=='D')
	{
		ans4=0;
	}
	if(s2[2]=='C'&&s1[2]=='D')
	{
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
