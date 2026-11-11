#include <bits/stdc++.h>

#define ll long long

#define fileio(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout);

using namespace std;

const int maxn = 5e5 + 15;

ll a[maxn];
ll pa[maxn];
int n;
ll m;

int main() {
	fileio("crystal")
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i++) {
		pa[i] = pa[i - 1] + a[i];
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int best = -1;
		
		while(l <= r) {
			int mid = (l + r) >> 1;
			
			if(a[i] * (i - mid + 1) - pa[i] + pa[mid - 1] > m) {
				l = mid + 1;
			} else {
				r = mid - 1;
				best = i - mid + 1;
			}
		}
		
		ans = max(ans, best);
	}
	
	cout << ans << '\n';
	
	return 0;
}
