#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string txt="",a="";

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1,c; i<=n; i++) {
		cin>>c;
		cin>>a;
		for(ll j=1;j<=c;j++)txt+=a;
	}
//	cout<<txt;
//	return 0;
	ll len=txt.length();
	ll ans=0;
	ll mid=(len)/2;
	for(ll i=0; i<mid; i++) {
//		cout<<txt[i];
		if(txt[i]!=txt[len-i-1]) {
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
