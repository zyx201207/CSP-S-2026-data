#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a;
ll cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c,l,r;	
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a >> s;
		for(ll j=1;j<=a;j++) c+=s;
	}
	l = c.substr(0,c.size()/2);
	r = c.substr(ceil(c.size()*1.0/2));
	for(ll i=0;i<l.size();i++){
		if(l[i] != r[i]) cnt++;
		if(r[i] != l[i]) ans++;
	}
	cout << min(cnt,ans);
	return 0;
}
