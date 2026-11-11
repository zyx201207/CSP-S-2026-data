#include<bits/stdc++.h>
using namespace std;
int c,c1;
string s,s1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1) cout<<"1";
	else 
	{
		cout<<"0000"<<endl;
		return 0;
	}
	int a=(s[0]-'0')*10+s[1]-'0';
	int b=(s1[0]-'0')*10+s1[1]-'0';
	if(a==b) cout<<"1";
	else 
	{
		cout<<"000"<<endl;
		return 0;
	}
	if(s[2]<='C'&&s[2]>='A'&&s1[2]<='C'&&s1[2]>='A') cout<<"1";
	else if(s[2]<='F'&&s[2]>='D'&&s1[2]<='F'&&s1[2]>='D') 
	{
		cout<<"11"<<endl;
		return 0;
	}
	else
	{
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(s[2]-s1[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
