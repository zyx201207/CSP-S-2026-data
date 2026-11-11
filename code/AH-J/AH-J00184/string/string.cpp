#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e7 + 5;
char s[maxn];
ll ans[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	cin >> n;
	ll l = 0;
	
	for(ll i = 1; i <= n; ++i){
		ll a;
		char b;
		cin >> a >> b;
		s[i] = b;
		ans[i] = a;
	}
	l = n;
	ll cnt = 0;
	ll i = 1;
	while(1){
		if(ans[i] == 0 || ans[l] == 0 || i == l){
			break;
		}
		else if(ans[i] > ans[l]){
			if(s[i] == s[l]){
				ans[i] -= ans[l];
			}
			else if(s[i] != s[l]){
				ans[i] -= ans[l];
				cnt += ans[l];
			}
			ans[l] = 0;
			l -= 1;
		}
		else if(ans[i] < ans[l]){
			if(s[i] == s[l]){
				ans[l] -= ans[i];
			}
			else if(s[i] != s[l]){
				ans[l] -= ans[i];
				cnt += ans[i];
			}
			ans[i] = 0;
			i += 1;
		}
		else if(ans[i] == ans[l]){
			if(s[i] != s[l]) cnt += ans[i];
			ans[i] = 0;
			i += 1;
			ans[l] = 0;
			l -= 1;
		}
	}
	cout << cnt;
	return 0;
}
