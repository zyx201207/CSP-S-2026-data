#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
map<char,int>mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;mp['B']=2;mp['C']=3;mp['D']=101;mp['F']=102;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else{cout<<"0000";return 0;}
	if(s2[0]==s4[0]&&s2[1]==s4[1])cout<<1;
	else{cout<<"000";return 0;}
	if(abs(mp[s2[2]]-mp[s4[2]])<=5)cout<<1;
	else{cout<<"00";return 0;}
	if(abs(mp[s2[2]]-mp[s4[2]])<=1)cout<<1;
	else cout<<0;
	return 0;
}
