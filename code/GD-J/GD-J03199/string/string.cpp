#include <bits/stdc++.h>
#define DEBUG 0
#if DEBUG
#define bug(x) cout << "[DEBUG] " << #x << " = " << x << '\n';
#else
#define bug(x)
#endif
using namespace std;
using ll = unsigned long long;
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i ++){
		char ss;
		ll x;
		cin >> x >> ss;
		while(x --) s += ss;
	}
	ll mid;
	ll ans = 0;
	//cout << "[DEBUG] " << "s.size()" << " = " << s.size() << '\n';
	if(s.size() % 2 == 1) mid = ((s.size()+1)>>1)-1;
	else mid = s.size()/2;
	bug(mid);
	if(s.size() % 2 == 0){
		for(ll i = 0, j = mid; i < mid && j < s.size(); i ++, j ++){
			if(s[i] != s[j]){
				ans ++;
			}
		}
	}
	if(s.size() % 2 == 1){
		for(ll i = 0, j = mid + 1; i < mid && j < s.size(); i ++, j ++){
			if(s[i] != s[j]){
				ans ++;
			}
		}
	}
	//cout << s.size() << ' ' << s;
	/*
	ll mid;
	if(s.size() % 2 == 1) mid = ((s.size()+1)>>1)-1;
	else mid = s.size()/2;
	string a,b;
	if(s.size()%2 == 0){
		for(ll i = 0; i < mid; i ++) a += s[i];
		for(ll i = mid; i < s.size(); i ++) b += s[i];
	}else{
		for(ll i = 0; i < mid; i ++) a += s[i];
		for(ll i = mid+1; i < s.size(); i ++) b += s[i];
	} 
	
	//cout << a << ' ' << d;
	if(a == b){
		cout << 0;
		return 0;
	}
	ll ans = 0;
	for(ll i = 0; i < a.size(); i ++){
		if(a[i] != b[i]){
			a[i] = b[i];
			ans ++;
		}
	}*/
	cout << ans;
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
