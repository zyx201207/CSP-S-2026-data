#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s=" ";
ll n,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		l+=a;
		for(ll j=1;j<=a;j++){
			s.push_back(c);
		}
	}
	ll ans=0;
	for(ll i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}



