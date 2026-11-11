#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen(".\\string.in", "r", stdin);
	freopen(".\\string.out", "w", stdout);
	ll n,a,L=0,ans=0;
	char c;
	string s;
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a>>c;
		L += a;
		for(ll j=1;j<=a;++j){
			s+=c;
		}
	}

	for(ll i=0;i<s[i];++i){
		if(s[i]!=s[L+1-i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
