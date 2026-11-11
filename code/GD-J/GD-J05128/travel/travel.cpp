#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int f,k;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f=1;
		cout<<"1";
	}
	else
		cout<<"0";
	if(f&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		k=1;
		cout<<"1";
	}
	else
		cout<<"0";
	if(k&&(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'))
	{
		cout<<"11";
	}
	else if(k&&(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'))
		cout<<"10";
	else
		cout<<"00";
	return 0;
} 
