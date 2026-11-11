#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	cin.tie(0)->sync_with_stdio(0);
	cin>>s>>s1>>s2>>s3;
	if(s==s2) cout<<1;
	else cout<<0;
	if(s==s2&&s1[0]==s3[0]&&s1[1]==s3[1]) cout<<1;
	else cout<<0;
	if(s==s2&&(s1[0]==s3[0]&&s1[1]==s3[1])&&mp[s1[2]]==mp[s3[2]]) cout<<1;
	else cout<<0;
	if(s==s2&&((s1[0]==s3[0]&&s1[1]==s3[1])&&mp[s1[2]]==mp[s3[2]])&&abs(s1[2]-s3[2])==1) cout<<1;
	else cout<<0;
	return 0;
} 
