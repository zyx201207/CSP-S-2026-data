#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		ans+="1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1])
		ans+="1";
	else
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C' || s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')
		ans+="1";
	else
	{
		cout<<"1100";
		return 0;
	}
	if(s1[2]+1==s2[2])
		ans+="1";
	else
		ans+="0";
	cout<<ans;
	return 0;
}
