#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","out",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<'1';
	else 
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		s1+=c2[i];
		s2+=c4[i];
	}
	if(s1==s2) cout<<'1';
	else 
	{
		cout<<"000";
		return 0;
	}
	if(c2[2]=='A')
	{
		if(c4[2]=='B'||c4[2]=='C')cout<<'1';
		else cout<<"0";
	}
	else if(c2[2]=='B')
	{
		if(c4[2]=='A'||c4[2]=='C')cout<<'1';
		else cout<<"0";
	}
	else if(c2[2]=='C')
	{
		if(c4[2]=='B'||c4[2]=='A')cout<<'1';
		else cout<<"0";
	}
	else if(c2[2]=='D')
	{
		if(c4[2]=='F')cout<<'1';
		else cout<<"0";
	}
	else if(c2[2]=='F')
	{
		if(c4[2]=='D')cout<<'1';
		else cout<<"0";
	}
	if(c2[2]=='A')
	{
		if(c4[2]=='B')cout<<'1';
		else cout<<'0';
	}
	else if(c2[2]=='B')
	{
		if(c4[2]=='A'||c4[2]=='C')cout<<'1';
		else cout<<'0';
	}
	else if(c2[2]=='C')
	{
		if(c4[2]=='B')cout<<'1';
		else cout<<'0';
	}
	else if(c2[2]=='D')
	{
		if(c4[2]=='F')cout<<'1';
		else cout<<'0';
	}
	else if(c2[2]=='F')
	{
		if(c4[2]=='D')cout<<'1';
		else cout<<'0';
	}
	return 0;
}
