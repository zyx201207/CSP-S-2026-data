#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld", &n);
	string s;
	while(n--){
		ll a;
		char c;
		scanf("%lld %c", &a,&c);
		for(ll i = 1;i <= a;++i) s += c;//直接构建一个字符串
	}
	ll ans = 0;
	ll len = s.size();
	for(ll i = 0;i < len / 2;++i){
		//也就是说,字符串 S 是回文串,当且仅当对于所有 i (1 ≤ i ≤ L),均有 si = sL - 1−i 。
		if(s[i] != s[len - i - 1]) ans++;
	}cout << ans;
	return 0;
}
