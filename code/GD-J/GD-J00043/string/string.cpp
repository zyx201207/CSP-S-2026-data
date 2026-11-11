#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
string s;
ll ans;

void solve(){
	cin >> n;
	for(ll i = 1;i<=n;i++){
		ll a;char c;
		cin >> a >> c;
		while(a--)s += c;
	}
	ll cnt = s.size();
	s = ' '+s;
	for(ll i = 1;i<=cnt/2+1;i++){
		if(s[i]!=s[cnt+1-i])ans++;
	}
	cout << ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}


