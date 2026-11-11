#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll INF = 1e18 + 5;

int n, ans;
ll m, a[N];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	
	int l = 1;
	ll sum = 0;
	for (int r = 1; r <= n; r++) {
		sum += (a[r] - a[r - 1]) * (r - l);

		while (sum > m) {
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}

