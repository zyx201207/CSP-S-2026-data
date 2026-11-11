#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
bool ch(string a,string b)
{
	char x=a[2],y=b[2];
	return ((x=='F'&&y=='D')||(x=='D'&&y=='F')||((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')));
}
bool ch1(string a,string b)
{
	char x=a[2],y=b[2];
	if((x=='C'&&y=='D')||(x=='D'&&y=='C'))
		return false;
	if((x=='D'&&y=='F')||(x=='F'&&y=='D'))
		return true;
	return (abs(x-y)==1);
}
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
	else
		cout<<"1";
	if(!((s1[0]==s2[0])&&(s1[1]==s2[1])))
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(!ch(s1,s2))
	{
		cout<<"00";
		return 0;
	}
	else
		cout<<"1";
	if(ch1(s1,s2)==false)
		cout<<"0";
	else
		cout<<"1";
	return 0;
} 
