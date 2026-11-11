#include<bits/stdc++.h>
using namespace std;
long long n,a,t;
string s,c;
bool hui(string s){
	string x;
	for(int i=s.size()-1;i>=0;i--){
		x+=s[i];
	}
	if(x==s){
		return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	if(hui(s)){
		cout<<0;
	}
	else{
		cout<<s.size()/2;
	}
	return 0;
}
