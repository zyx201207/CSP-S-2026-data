#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
	}
	else if(c1[1]==c2[1]&&s1[1]!=s2[1])
	{
		cout<<"1000";
	}
	else if(s1[2]=='A'&&s2[2]=='B')
	{
		cout<<"1111";
	}
	else if(s1[2]=='A'&&s2[2]=='C')
	{
		cout<<"1111";
	}
	else if(s1[2]=='B'&&s2[2]=='C')
	{
		cout<<"1111";
	}
	else if(s1[2]=='B'&&s2[2]=='A')
	{
		cout<<"1111";
	}
	else if(s1[2]=='C'&&s2[2]=='B')
	{
		cout<<"1111";
	}
	else if(s1[2]=='C'&&s2[2]=='A')
	{
		cout<<"1111";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='D'){
		cout<<"1100";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='F'){
		cout<<"1100";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='D'){
		cout<<"1100";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='F'){
		cout<<"1100";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='D'){
		cout<<"1100";
	}
	else if(c1==c2&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='F'){
		cout<<"1100";
	}
	return 0;
}
