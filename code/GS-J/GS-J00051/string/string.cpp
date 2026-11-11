#include <bits/stdc++.h>
using namespace std;
long long n,ans,anss;
string s;
bool hui(string s){
	string ss;
	int len =s.length();
	for(int i=len-1;i>=0;i--){
		ss+=s[i];
	}
	if(ss==s){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++)s+=b;
	}
	if(hui(s))cout<<0;
	int len=s.length();
	for(int i=len-1;i>=0;i--){
		s[i]=s[len-i-1];
		ans++;
		if(hui(s)){
			break;
		}
	}
	for(int i=0;i<len;i++){
		s[i]=s[len-i+1];
		anss++;
		if(hui(s)){
			break;
		}
	}
	cout<<max(ans,anss);
	return 0;
}
