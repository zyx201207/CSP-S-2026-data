#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 1;

ll a[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, ans = 0, need = 0;
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(ll i=1, j=1; i<=n; i++){
		need += (i - j) * (a[i] - a[i - 1]);
		while(need > m){
			need -= a[i] - a[j];
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
