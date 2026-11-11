#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, a[N], s[N];

int main(){

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, mid, res = -1;
		while(l <= r){
			mid = ((r - l) >> 1) + l;
			if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		assert(res != -1);
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';

	return 0;
}