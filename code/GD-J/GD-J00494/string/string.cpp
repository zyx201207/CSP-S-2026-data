#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum; cin>>n;
	char a;
	string s = "0",sn = "0";
	for(long long i=1;i<=n;i++) {
		cin>>sum>>a;
		for(int j=1;j<=sum;j++) {
			s+=a;
		} 
	}
	s.erase(0,1);
	sn = s;
	reverse(sn.begin(),sn.end()); 
	if(sn == s) {
		cout<<0;
		return 0;
	}
	long long ans = 0;
	for(long long i=0;i<s.size()/2;i++) {
		if(s[i] != s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
} 
