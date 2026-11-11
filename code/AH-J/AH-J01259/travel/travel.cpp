#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
	{
		cout<<1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char x=s1[2],r=s2[2];
	if((x=='A'&&r=='B')||(x=='A'&&r=='C')||(x=='B'&&r=='C')||(x=='B'&&r=='A')||(x=='C'&&r=='A')||(x=='C'&&r=='B')||(x=='D'&&r=='F')||(x=='F'&&r=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((x=='A'&&r=='B')||(x=='B'&&r=='A')||(x=='B'&&r=='C')||(x=='C'&&r=='B')||(x=='D'&&r=='F')||(x=='F'&&r=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
