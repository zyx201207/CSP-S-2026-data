#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll a[N], s[N];
int n, ans = 1;
ll m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i){
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, res = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if((ll)(i - mid) * a[i] - s[i - 1] + s[mid - 1] <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}
//I often recall the past.
//Where shall I pause? I ask myself.
