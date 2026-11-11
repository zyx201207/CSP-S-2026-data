#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a;
ll n,x;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		cin>>x>>a;
		for(ll j=1;j<=x;j++) s+=a;
	}
	ll ans=0;
	for(ll i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) ans++;
	printf("%lld",ans);
	return 0;
}
