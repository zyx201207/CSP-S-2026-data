//GZ-S00140 贵阳市第一中学 赵思翰

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e6 + 5;

ll c, t;
ll n, d;
ll x[MAXN];
ll mn, mni;

ll dfs(ll ed, ll d, ll nw, ll len) {
	if(nw == ed) {
		if(len < mn) mn = len, mni = 1;
		else if(len == mn) mni++;
		return mni;
	}
	if(len >= mn) return mni;
	for(ll i = nw + 1; i <= ed; i++) {
		if(x[i] - x[nw] <= d) {
			dfs(ed, d, i, len + 1);
		}
	}
	return mni;
}

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	while(t--) {
		ll ans = 0;
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for(ll i = 1; i <= n; i++) cin >> x[i];
		
		for(ll i = 1; i <= n; i++) {
			for(ll j = i + 1; j <= n; j++) {
				mn = 0x3f, mni = 0;
				ll k = dfs(j, d, i, 0);
				if(k == 2) {
					ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
} 
