#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
map<char,int>mp,mp2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=2;
	mp['F']=2;
	mp2['A']=1;
	mp2['B']=2;
	mp2['C']=3;
	mp2['D']=5;
	mp2['F']=6;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2)<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]])<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&mp[s1[2]]==mp[s2[2]]&&abs(mp2[s1[2]]-mp2[s2[2]])==1);
	return 0;
}
