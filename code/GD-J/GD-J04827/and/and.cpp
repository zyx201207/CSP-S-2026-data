#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, m, a[N], t[N], maxx;
bool vis[N];
void dfs(ll x) {
	if(x > m) {
		ll cnt = t[1];
		for(ll i = 2; i <= m; i++) {
			cnt = (cnt & t[i]);
		}
		maxx = max(maxx, cnt);
		return;
	}
	for(ll i = 1; i <= n; i++) {
		if(vis[i])continue;
		vis[i] = true;
		t[x] = a[i];
		dfs(x+1);
		vis[i] = false;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	dfs(1);
	cout << maxx;
	return 0;
}
