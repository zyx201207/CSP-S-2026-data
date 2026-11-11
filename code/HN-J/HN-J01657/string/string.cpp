#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ans=0;
	string s="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i] != s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
