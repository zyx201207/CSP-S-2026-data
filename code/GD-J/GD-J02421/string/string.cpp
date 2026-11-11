#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool check(string s){
	for(int i=0,j=s.size()-1;i<s.size(),j>=i;i++,j--){
		if(s[i]!=s[j]) return false;
	}
	return true;
}
string fz(string s){
	for(int i=0;i<s.size();i++){
		char tmp=s[i];
		s[i]=s[s.size()-i];
		s[s.size()-i]=tmp;
	}
	return s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		string b;
		cin>>b;
		for(int j=1;j<=x;j++){
			s+=b;
		}
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0,j=s.size()-1;i<s.size(),j>=i;i++,j--){
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	return 0;
} 
