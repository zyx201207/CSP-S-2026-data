#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 100;

int num[maxn], sum[maxn];
int n;

bool check(int l, int r, int m) {
	
	int sm = sum[r - 1] - sum[l - 1];
	
	if(m >= (r - l) * num[r] - sm)
		return 1;
	else
		return 0;
}

signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int m;
	cin >> n >> m;
	
	
	for(int i = 1; i <= n; i ++) {
		cin >> num[i];
	}
	
	
	sort(num + 1, num + n + 1);
	
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + num[i];
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i ++) {
		
		int l = 1, r = i, pos = 0;
		
		while(l <= r) {
			int mid = (l + r) >> 1;
			
			if(check(mid, i, m)) {
				r = mid - 1;
				pos = mid;
			} else {
				l = mid + 1;
			}
		}
		
		ans = max(ans, i - pos + 1);
	}
	
	cout << ans;
}

