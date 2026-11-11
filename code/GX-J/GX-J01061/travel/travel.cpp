#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<0000;
			return 0;
		}
	}
	char s11,s22;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	s11=s1[2];
	s22=s2[2];
	if(s11>s22&&s11-s22>1&&(s11>='D'&&s11!='F'))
	{
		cout<<"1100";
		return 0;
	}
	else if(s11>s22&&s11-s22>1&&s11!='F')
	{
		cout<<"1110";
		return 0;
	}
	if(s11<s22&&s22-s11>1&&(s22>='D'&&s22!='F'))
	{
		cout<<"1100";
		return 0;
	}
	else if(s22>s11&&s22-s11>1&&s22!='F')
	{
		cout<<"1110";
		return 0;
	}
	cout<<1111;
	return 0;
}
