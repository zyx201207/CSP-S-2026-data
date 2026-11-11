#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll maxn = 2e5 + 5;
ll n , m;
ll a[maxn],c[maxn],s[maxn];
void solve(){
	cin >> n >> m;
	const ll M = m;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
	}
		
	sort(a + 1 , a + n + 1);
	
	for (ll i = 1; i <= n; i++){
		c[i] = a[i] - a[i - 1];
	}
	
	ll res = 0 , cur = 0 , now = 0;
	
	for (ll i = 2; i <= n; i++){
		if (now > M) break;
		res++;
		now = 0;
		for (ll j = i; j >= 2; j--){
			now += (c[j] * (j - 1));
		}
	}
	
	cout << res << endl;
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

