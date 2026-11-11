#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int x,y;
char c1,c2;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=105,mp['F']=106;
	cin>>s1>>t1>>s2>>t2;
	c1=t1[2],c2=t2[2],x=stoi(t1.substr(0,2)),y=stoi(t2.substr(0,2));
	if(s1==s2) cout<<1; else cout<<0;
	if(s1==s2&&x==y) cout<<1; else cout<<0;
	if(s1==s2&&x==y&&abs(mp[c1]-mp[c2])<=2) cout<<1; else cout<<0;
	if(s1==s2&&x==y&&abs(mp[c1]-mp[c2])<=2&&abs(mp[c1]-mp[c2])==1) cout<<1; else cout<<0;
	return 0;
}

