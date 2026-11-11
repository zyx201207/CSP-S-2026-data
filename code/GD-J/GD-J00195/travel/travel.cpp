#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll s1,s3;
string s2,s4;
ll flag;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else flag=1,cout<<0;
	if(flag==0&&s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
	else flag=1,cout<<0;
	if(flag==0)
	{
		if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')cout<<1;
		else if((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F'))cout<<1;
		else cout<<0,flag=1;
	}
	else cout<<0;
	if(flag==0)
	{
		if(s2[2]=='A'&&s4[2]=='B')cout<<1;
		else if(s2[2]=='B'&&s4[2]=='C')cout<<1;
		else if(s2[2]=='D'&&s4[2]=='F')cout<<1;
		else if(s4[2]=='A'&&s2[2]=='B')cout<<1;
		else if(s4[2]=='B'&&s2[2]=='C')cout<<1;
		else if(s4[2]=='D'&&s2[2]=='F')cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
