#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6+10;
ll x[maxn];
int n; ll d; 

int count(int u, int v, int mn) {
	if(mn == 0 && u != v) return 0;
	else if(u == v) return 1;
	int cnt = 0;
	for(int i = u+1; i <= v; i++) {
		if((x[i]-x[u]) <= d) cnt += count(i, v, mn-1);
		else break ;
	}
	return cnt;
}

bool check(int u, int v) {
	int mn = 1;
	ll dist = 0;
	for(int i = u; i <= v; i++) {
		if((x[i+1] - x[i] + dist) > d) {
			if((x[i+1]-x[i]) > d) return false;
			dist = 0; mn++;
		} 
		dist += x[i+1] - x[i];
	}
	if(count(u, v, mn) == 2) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		ll ans = 0;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++) {
			for(int j = i+2; j <= n; j++) {
				if(check(i, j)) ans++;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
