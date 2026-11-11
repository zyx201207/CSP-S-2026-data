#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int k(string s){
	if(s[2]>'C')return 1;
	return 0;
}
bool check(string s1,string s2){
	return (s1[2]==s2[2]+1||s1[2]+1==s2[2]);
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else {
		cout<<"0000";
		return 0;
	}
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
		cout<<"000";
		return 0;
	}
	if(k(s1)==k(s2))cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(check(s1,s2))cout<<1;
	else cout<<0;
    return 0;
}
