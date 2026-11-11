#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll a;
char s;
string c = "";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a>>s;	
		for(ll j=1;j<=a;j++){
			c+=s;
		}
	}
	ll ans=0;
	ll m = (c.size() / 2LL);
	for(ll i=0;i<m;i++){
		if(c[i] != c[m+1-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}


