#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r".stdin);
	freopen("string.out","w".stdout);
	string s;
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int i=0;i<x;i++){
			s+=a;
		}
	}
	int p=s.size()/2;
	string k;
	for(int i=s.size()-1;i>p;i--){
		k+=s[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==k[i]){
			
		}else{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}

