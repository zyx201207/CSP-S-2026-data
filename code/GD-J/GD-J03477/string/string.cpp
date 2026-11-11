#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		char c; cin>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		} 
	}
	int ans=0;
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]) ans++;
	}
	cout<<ans;
	
	return 0;
} 
