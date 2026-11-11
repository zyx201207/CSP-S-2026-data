#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int e;
		char ch;
		cin>>e>>ch;
		for(int j=0;j<e;j++) s+=ch;
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
}
