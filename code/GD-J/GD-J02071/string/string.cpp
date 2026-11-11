#include<bits/stdc++.h>
using namespace std;
stack<char>str;
string s;
string a;
int c=0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int i=0;i<x;i++) {
			s+=y;
		}
		
	}
	//cout<<s;
	for(int i=0;i<s.size();i++){
		str.push(s[i]);
	}
	for(int i=0;i<s.size();i++){
		a+=str.top();
		str.pop();
	}
	for(int i=0;i<s.size()/2;i++){
		if(a[i]!=s[i]){
			c++;
		}
	}
	cout<<c;
	return 0;
}
