//GZ-J00026 贵阳市白云区华师一学校 杨泊静 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
bool is(string s){
	string a = "";
	ll len = s.size();
	for(ll i = len-1; i >= 0; i--){
		a += s[i];
	}
	if(a == s) return true;
	else return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,len = 0;
	string s = "";
	scanf("%lld",&n);
	if(n == 1) cout << 0;
	for(ll i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		cin >> c[i];
		len += a[i];
	}
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= a[i]; j++)
			s += c[i];
	if(is(s)) cout << 0;
	return 0;
}
