#include<bits/stdc++.h>
using namespace std;
int sti(string s){
	int sum=0;for(int i=0;i<s.size();i++)sum+=sum*10+(s[i]-'0');
	return sum;
}
map<char,int> m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	m['A']=0,m['B']=0,m['C']=0,m['D']=1,m['F']=1;
	if(sti(c1)==sti(c2))cout<<1;else cout<<0;
	if(sti(c1)==sti(c2)&&sti(s1.substr(0,2))==sti(s2.substr(0,2)))cout<<1;else cout<<0;
	if(sti(c1)==sti(c2)&&sti(s1.substr(0,2))==sti(s2.substr(0,2))&&m[s1[2]]==m[s2[2]])cout<<1;else cout<<0;
	if(sti(c1)==sti(c2)&&sti(s1.substr(0,2))==sti(s2.substr(0,2))&&m[s1[2]]==m[s2[2]]&&abs(s1[2]-s2[2])==1)cout<<1;else cout<<0;
	return 0;
}
//6767676767676767676767
