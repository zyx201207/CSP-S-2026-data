#include<bits/stdc++.h>
using namespace std;
bool f(string s){
	long long a=s.size()-1;
	for(int i=0;i<a/2;i++){
		if(s[i]!=s[a-i])return 0;
	}
	return 1;
}
long long n,x=0,a;
string s,st;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		x+=a;
		for(int j=1;j<=a;j++){
			st=st+s;
		}
	}
	if(f(st)){cout<<"0";return 0;}
	else{cout<<x/2;return 0;}
	return 0;
}
