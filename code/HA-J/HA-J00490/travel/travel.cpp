#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int abc(char c)
{
	if(c=='A' or c=='B' or c=='C')return 0;
	else return 1;
}
int main()  
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1])cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	if(abc(s1[2])==abc(s2[2]))cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abc(s1[2])==1 or abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
