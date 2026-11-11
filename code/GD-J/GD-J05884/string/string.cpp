#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,l,r;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long t;
		string a;
		cin>>t;
		cin>>a;
		while(t--) s+=a;
	}
	l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		++l;
		--r;
	}
	cout<<ans;
	return 0;
} 
