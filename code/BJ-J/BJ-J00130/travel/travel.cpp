#include<bits/stdc++.h>
using namespace std;
bool side(string s){
	return 'A'<=s[2]&&s[2]<='C';
}
string f(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		return "0000";
	if(s1.substr(0,2)!=s2.substr(0,2))
		return "1000";
	if(side(s1)!=side(s2))
		return "1100";
	if(abs(s1[2]-s2[2])+side(s1)!=2)
		return "1110";
	return "1111";
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cout<<f();
	return 0;
}
