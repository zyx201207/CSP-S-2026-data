#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int num1=0,num2=0;

	if(stoll(s1)==stoll(s2))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	char a=s2[2],b=s4[2];
	s2.pop_back();
	s4.pop_back();
	if(stoll(s2)==stoll(s4))
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(a=='A'&&(b=='B'||b=='C')||a=='B'&&(b=='A'||b=='C')||a=='C'&&(b=='A'||b=='C')||a=='E'&&b=='F'||a=='F'&&b=='E')
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='B'&&b=='C'||a=='E'||a=='F')
	cout<<"1";
	else
	cout<<"0";
	return 0;
}
