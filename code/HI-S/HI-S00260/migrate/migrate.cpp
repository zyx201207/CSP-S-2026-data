#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int c, t;
ll n, d, x[2000005], ans=0, minstep;

int dfs(int l, int r, int step) {
	if (l==r) {
		if (step>minstep) return 0;
		else {
			minstep = step;
			return 1;
		}
	}
	int cnt = 0;
	for (int i=r; i>=l+1; i--) {
		if (x[i]-x[l]>d) continue;
		cnt+=dfs(i, r, step+1);
	}
	return cnt;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i=1; i<=n; i++) {
			cin >> x[i];
			for (int j=1; x[i]-x[j]>d; j++) {
				minstep = 1e18;
				if (dfs(j, i, 1)==2) ++ ans;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}

