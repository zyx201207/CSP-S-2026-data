#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
bool cmp1(string str1,string str2){
	char c1=str1[2],c2=str2[2];
	if(c1>c2) swap(c1,c2);
	if(c1=='D'&&c2=='F') return 1;
	if(c1=='D'||c2=='D') return 0;
	if(c1=='F'||c2=='F') return 0;
	return 1;
}
bool cmp2(string str1,string str2){
	char c1=str1[2],c2=str2[2];
	if(c1>c2) swap(c1,c2);
	if(c1=='A'&&c2=='B') return 1;
	if(c1=='B'&&c2=='C') return 1;
	if(c1=='D'&&c2=='F') return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	if(cmp1(s2,s4)) cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	if(cmp2(s2,s4)) cout<<1;
	else cout<<0;
	return 0;
}
