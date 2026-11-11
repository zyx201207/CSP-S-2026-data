#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	for(auto &v : a) cin >> v;
	sort(a.begin(), a.end());
	
	int ans = 0;
	for(int l = 0, r = 1, num = 0; r < n; r ++){
		while(num + (a[r] - a[r - 1]) * (r - l) > m){
			num -= a[r - 1] - a[l];
			l ++;
		}
		num += (a[r] - a[r - 1]) * (r - l); 
		ans = max(ans, r - l + 1);
	}
	
	cout << ans << '\n';
}
