#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ans;
ll a[500005];
int f(int u, ll m){
	int cnt = 1;
	for(int i = u - 1; i >= 1; i--){
		if(a[u] - a[i] <= m){
			cnt++;
			m -= (a[u] - a[i]);
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n;
	ll m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) ans = max(ans, f(i, m));
	cout << ans;
	return 0;
}
