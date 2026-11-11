#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
#define int long long

int n, m, a[N], ans;

void solve(){
	int sum, l, r;  // sum = sum([delta l, delta r])
	
	l = r = ans = 1;sum = 0;
	while(r <= n){
		r++;
		sum = sum - (a[r] - a[r - 1]) + (r - l + 1) * (a[r] - a[r - 1]);
		while(sum > m){
			l++;
			sum = sum - (a[r] - a[l - 1]);
		}
		ans = max(ans, r - l + 1);
	}
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1){
		cout << "1\n";
		return 0;
	}
	sort(a + 1, a + 1 + n);
	solve();
	cout << ans << '\n';
	return 0;
} 
