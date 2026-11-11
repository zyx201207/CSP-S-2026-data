#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5+5;

ll n, m, a[maxn], ans, vis[maxn];

void dfs(ll now, int k){
	if(k == m){
		ans = max(ans, now);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(now & a[i], k+1);
		vis[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and3.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	ll mx = 0, mn = 1 << 31;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(((a[i] + 1) & a[i]) == 0) cnt++;
		mx = max(mx, a[i]);
		mn = min(a[i], mn);
	}
	if(m == 1) {
		cout << mx;
		return 0;
	}
	if(cnt >= n){
		sort(a+1, a+n+1, [](ll l, ll r){
			return l > r;
		});
		cout << a[m];
		return 0;
	}
	
	if(m == n){
		ans = a[1];
		for(int i = 2; i = n; i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	
	if(m == 2){
		sort(a+1, a+n+1, [](ll l, ll r){
			return l > r;
		});
		for(int i = 2; i <= n; i++){
			if(a[i] == a[i-1]){
				ans = max(a[i], ans);
				break;
			}
		}
	}
	
	dfs(1 << 31+1, 0);
	cout << ans;
	return 0;
}



/*
      _|          _|_|_|
     _|_|       _|      _|
    _|  _|     _|         
   _|    _|    _|       
  _|_|_|_|_|   _|        
 _|        _|   _|      _|
_|          _|    _|_|_|
*/
