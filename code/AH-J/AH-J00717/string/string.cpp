#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		ll x;char c;
		scanf("%lld %c",&x,&c);
		while(x--) s+=c;
	}
	ll l=s.size();
	for(ll i=0;i<l/2+1;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			cnt++;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
