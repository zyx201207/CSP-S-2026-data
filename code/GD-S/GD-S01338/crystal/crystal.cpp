#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 9;
ll a[maxn];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	ll m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1;
	ll tot = 0;
	for(int i = 1;i <= n;i++){
		tot += a[i];
		while(l <= i && a[i] * (i - l + 1) - tot > m) tot -= a[l++];
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}

