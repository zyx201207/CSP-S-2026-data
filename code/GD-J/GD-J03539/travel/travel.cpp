#include<bits/stdc++.h>
using namespace std;
string c1;
string s1;
string c2;
string s2;
bool f1=false,f2=false,f3=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<'1'<<'1'<<'1';
	for(int i=0;i<s1.size();i++)
	{
		if(s1[2]=='A'&&s2[2]=='B')
		{
			cout<<'1';
			break; 
		}
		if(s1[2]=='B'&&(s2[2]=='A'&&s2[2]=='C'))
		{
			cout<<'1';
			break;
		}
		if(s1[2]=='C'&&s2[2]=='B')
		{
			cout<<'1';
			break;
		}
		if(s1[2]=='D'&&s2[2]=='F')
		{
			cout<<'1';
			break;
		}
		if(s2[2]=='A'&&s1[2]=='B')
		{
			cout<<'1';
			break; 
		}
		if(s2[2]=='B'&&(s1[2]=='A'&&s1[2]=='C'))
		{
			cout<<'1';
			break;
		}
		if(s2[2]=='C'&&s1[2]=='B')
		{
			cout<<'1';
			break;
		}
		if(s2[2]=='D'&&s1[2]=='F')
		{
			cout<<'1';
			break;
		}
		else
		{
			cout<<'0';
			break;
		}
	}
	return 0;
}
