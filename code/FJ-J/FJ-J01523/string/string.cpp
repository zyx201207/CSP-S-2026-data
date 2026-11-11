#include<bits/stdc++.h>
using namespace std;
long long str(string s){
	long long x=s.size(),ans=0;
	string m="",n="";
	for(int i=0;i<x/2;i++) m+=s[i];
	for(int i=x-1;i>=x/2;i--) n+=s[i];
	for(int i=0;i<x/2;i++){
		if(m[i]!=n[i]) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	string s="",c;
	cin>>n;
	for(int i=0;i<n;i++){
		c="";
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
	}
	cout<<str(s);
	return 0;
}
