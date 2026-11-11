#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,ls;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(long long j=1;j<=t;j++) s+=c;
	}
	ls=s.size();
	for(long long i=0;i<ls/2;i++){
		if(s[i]!=s[ls-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
