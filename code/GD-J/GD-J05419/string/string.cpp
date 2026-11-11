#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long c=0;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char l;
		cin>>x;
		cin>>l;
		for(int j=0;j<x;j++){
			s=s+l;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			c++;
		}
	}
	cout<<c;
}
 
