#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s="0000";
	if(c1==c2){
		s[0]='1';
	}else{
		cout<<s<<endl;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		s[1]='1';
	}else{
		cout<<s<<endl;
		return 0;
	}
	bool ok=true;
	if(s1[2]<='C'&&s2[2]<='C'){
		s[2]='1';
		ok=false;
	}else if(s1[2]>='F'&&s[2]<='D'&&s1[1]>='F'&&s[1]<='D'){
		s[2]='1';
		ok=false;
	}
	if(ok){
		cout<<s<<endl;
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		s[3]='1';
	}else{
		cout<<s<<endl;
		return 0;
	}
	cout<<s<<endl;
	return 0;
}
