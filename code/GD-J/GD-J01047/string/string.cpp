#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[200010],ans = 0;
char c[200010];
string s = " ";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (ll i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	ll l = 1,r = n;
	while (l < r){
		if (c[l] != c[r]){
			ans += min(a[l],a[r]);
		}if (a[l] == a[r]){
			a[l] = 0;
			a[r] = 0;
			r--;l++;
		}else if (a[l] > a[r]){
			a[l] -= a[r];
			r--;
		}else{
			a[r] -= a[l];
			l++;
		}
	}cout << ans;
	return 0;
}
