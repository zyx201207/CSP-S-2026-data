#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
ll a[N], n, m, ans[N], mx;
bool vis[N];

void dfs(ll now){
	if(now == m + 1){
		mx = max(mx, ans[m]);
		return ;
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			if(now - 1 <= 0) ans[now] = a[i];
			else ans[now] = ans[now-1] & a[i];
			vis[i] = 1;
			dfs(now + 1);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out ", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	
	ll mxn = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		mxn = max(mxn, abs(a[i] - a[i-1])); 
	}
	
	if(mxn == 1){
		sort(a+1, a+n+1);
		ll ans = a[n];
		for(ll i = n-1; i > n - m; i--){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << mx;
	return 0;
}

