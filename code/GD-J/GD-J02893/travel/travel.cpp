#include<bits/stdc++.h>
using namespace std;
bool tong(char a,char b)
{
	if(a>b)
		swap(a,b);
	if(a=='D'&&b=='F')
		return 1;
	else if(a=='A'&&(b=='C'||b=='B'))
		return 1;
	else if(a=='B'&&b=='C')
		return 1;
	return 0;
}
bool ce(char a,char b)
{
	if(a>b)
		swap(a,b);
	if(a=='A'&&b=='B')
		return 1;
	else if(a=='B'&&b=='C')
		return 1;
	else if(a=='D'&&b=='F')
		return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
		cout<<1;
	else
		cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3)
		cout<<1;
	else
		cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&tong(s2[2],s4[2])&&s1==s3)
		cout<<1;
	else
		cout<<0;
	if(ce(s2[2],s4[2])&&s2[0]==s4[0]&&s2[1]==s4[1]&&tong(s2[2],s4[2])&&s1==s3)
		cout<<1;
	else
		cout<<0;
	return 0; 
 } 
