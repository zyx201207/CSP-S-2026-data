#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int ans=0,m;
	m=s.size()/2;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[i+m]){
			ans++;
		} 
	}
	cout<<ans;
	return 0;
} 
