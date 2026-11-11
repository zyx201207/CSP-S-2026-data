#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 5e5 + 5;

ll a[N];

ll cnt[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	for (ll i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	
	for (ll i = 1;i <= n;i ++) {
		vector<bool> vis(m + 1, false);
		stack<ll> stk;
		
		for (ll j = i;j <= n;j ++) {
			if (vis[a[j]]) {
				while (stk.size() != 0 && stk.top() != a[j]) {
					vis[stk.top()] = false;
					stk.pop();
				}
			} else {
				vis[a[j]] = true;
				stk.push(a[j]);
			}
		}
		
		for (ll i = 1;i <= m;i ++) {
			cnt[i] += vis[i];
		}
	}
	
	for (ll i = 1;i <= m;i ++) {
		cout << cnt[i] << " ";
	} 
	return 0;
}

/*
30
*/
