#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&mp[s1[2]]==mp[s2[2]])cout<<1;
	else cout<<0;
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&mp[s1[2]]==mp[s2[2]]&&(mp[s1[2]]==2||abs(s1[2]-s2[2])==1))cout<<1;
	else cout<<0;
} 
