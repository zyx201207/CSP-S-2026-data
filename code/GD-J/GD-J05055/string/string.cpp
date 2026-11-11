#include<bits/stdc++.h>
using namespace std;
bool aaa(string s){
	string k;
	for(int i=0;i<s.size();i++){
		k=s[i]+k;
	}
	if(k==s){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(long long i=0;i<n;i++){
		int d;
		cin>>d;
		char g;
		cin>>g;
		for(long long j=0;j<d;j++){
			s=s+g;
		}}
	if(aaa(s)){
		cout<<0;
		return 0;
	}else{
		cout<<s;
	}
	
	long long p=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i]){
			p++;
		}
	}
	cout<<p;
	return 0;
} 

