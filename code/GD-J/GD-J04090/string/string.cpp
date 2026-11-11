#include<bits/stdc++.h>
using namespace std;
int cnt,n;
string s="";
bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	while(n--){
		int len;
		char s1;
		cin>>len>>s1;
		for(int i=1;i<=len;i++){
			s+=s1;
		}
	}
	if(check(s)){
		cout<<0;
		retrun 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
