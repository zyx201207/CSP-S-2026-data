#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int a; cin>>a;
		char c; cin>>c;
		while(a--) s+=c;
	} 
	int cnt=s.size()/2;
	int j=s.size()-1;
	int ans=0;
	for(int i=0;i<cnt;i++){
		if(s[i]!=s[j]) ans++;
		j--;
	}
	cout<<ans;
	return 0;
} 
