#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for (int i=0;i<n;i++){
		ll a;
		string c;
		cin>>a>>c;
		for (ll i=0;i<a;i++){
			s+=c;
		}
	}
	ll ans=0;
	for (int i=0;i<s.size()/2;i++){
		if (s[i]!=s[n-i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
