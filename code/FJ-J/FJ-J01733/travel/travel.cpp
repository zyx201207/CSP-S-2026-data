#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s;
bool f1=0,f2=0,f3=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) {cout<<"1";f1=1;}
	else cout<<"0";
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&f1) {cout<<"1";f2=1;}//AC£¬100·Ö 
	else cout<<"0";
	if((((s2[2]>='A'&&s2[2]<='C')&&(s4[2]>='A'&&s4[2]<='C'))||((s2[2]>='D'&&s2[2]<='F')&&(s4[2]>='D'&&s4[2]<='F')))&&f1&&f2){cout<<"1";f3=1;}
	else cout<<"0";
	if(f1&&f2&&f3&&(s2[2]==s4[2]+1||s2[2]==s4[2]-1)) cout<<"1";
	else cout<<"0";
	return 0;
}
