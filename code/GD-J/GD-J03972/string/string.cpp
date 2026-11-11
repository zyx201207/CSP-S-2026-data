#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int x;
		char a;
		cin>>x>>a;
		for(int i=0;i<x;i++){
			s+=a;
		}
	}
	long long ans=0,l=s.size()/2;
//	for(int i=0;i<s.size();i++){
//		cout<<s[i]<<" ";
//	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

