#include<bits/stdc++.h>
using namespace std;
bool tx(string c1,string c2){
	return (c1==c2);
}bool tp(string s1,string s2){
	return (s1[0]==s2[0]&&s1[1]==s2[1]);
}bool tc(string s1,string s2){
	return ((s1[2]<='C'&&s2[2]<='C')||((s1[2]=='D'&&s1[2]=='F')||(s1[2]=='F'&&s2[2]=='D')));
}bool xl(string s1,string s2){
	return (s1[2]==s2[2]+1||s1[2]+1==s2[2]);
}int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(tx(c1,c2));
	cout<<(tx(c1,c2)&&tp(s1,s2));
	cout<<(tx(c1,c2)&&tp(s1,s2)&&tc(s1,s2));
	cout<<(tx(c1,c2)&&tp(s1,s2)&&tc(s1,s2)&&xl(s1,s2));
	return 0;
}