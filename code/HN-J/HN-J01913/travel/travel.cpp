#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	//freopen("cs-1.out","w",stdout);
	freopen("travel.out","w",stdout);
	//02 01A 02 01B

	string c1,s1,c2,s2;
	cin>>c1>>s1>>s2>>s2;
	
	cout<<"1";
	
	if(s1[0]==s2[0] && s2[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	if((s1[2]-'D')>=0 && (s2[2]-'D')>=0)
	{
		cout<<"1";
	}
	else if((s1[2]-'D')<0 && (s2[2]-'D')<0)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	
	if((s1[2]+1)==s2[2] || (s2[2]+1)==s1[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		return 0;
	}
	
	return 0;
}
