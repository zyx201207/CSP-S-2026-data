#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	char ch1=s1[2],ch2=s2[2];
	int id1=(s1[0]-'0')*10+s1[1]-'0';
	int id2=(s2[0]-'0')*10+s2[1]-'0';
	cout<<1;
	if(id1!=id2)
	{
		cout<<"000"; 
		return 0;
	}
	cout<<1;
	if(ch1=='D')
	{
		if(ch2=='F')cout<<"11";
		else cout<<"00";
		return 0;
	}
	if(ch1=='F')
	{
		if(ch2=='D')cout<<"11";
		else cout<<"00";
		return 0;
	}
	if(ch1=='A')
	{
		if(ch2=='B')cout<<"11";
		else if(ch2=='C')cout<<"10";
		else cout<<"00";
		return 0;
	}
	if(ch1=='B')
	{
		if(ch2=='A'||ch2=='C')cout<<"11";
		else cout<<"00";
		return 0;
	}
	if(ch1=='C')
	{
		if(ch2=='A')cout<<"10";
		else if(ch2=='B')cout<<"11";
		else cout<<"00";
		return 0;
	}
	return 0;
}

