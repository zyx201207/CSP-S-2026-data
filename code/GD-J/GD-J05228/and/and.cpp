#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, m, a[MAXN], l, r, ma, ans, tp, le, sum;
int dv[MAXN][35];
int mb[35];
bool vis[MAXN];

bool check(int x) {
	memset(mb, 0, sizeof(mb));
	
	le = 0;
	while (x > 0) {
		mb[le] = x % 2;
		x /= 2;
		le++;
	}
	
	bool zero = 1;
	
	memset(vis, 0, sizeof(vis));
	
	for (int i = 33; i >= 0; i--) {
		if (mb[i] != 0) {
			zero = 0;
		}
		
		if (zero) {
			sum = 0;
			
			for (int j = 1; j <= n; j++) {
				if (!vis[j]) {
					if (dv[j][i]) {
						sum++;
					}
				}
			}
			
			if (sum >= m) {
				return true;
			}
		}
		
		else {
			if (mb[i]) {
				sum = 0;
				for (int j = 1; j <= n; j++) {
					if (!vis[j]) {
						if (dv[j][i] == 0) {
							vis[j] = 1;
						}
						else {
							sum++;
						}
					}
				}
				
				if (sum < m) {
					return false;
				}
			}
			
			else {
				sum = 0;
				for (int j = 1; j <= n; j++) {
					if (!vis[j]) {
						if (dv[j][i]) {
							sum++;
						}
					}
				}
				
				if (sum >= m) {
					return true;
				}
			}
		}
	}
	
	return true;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);
		tp = a[i];
		le = 0;
		while(tp > 0) {
			dv[i][le] = tp % 2;
			tp /= 2;
			le++;
		}
	}
	
	
	//cout << check(7) << endl;
	
	r = ma;
	while(l <= r) {
		int mid = (l + r) / 2;
		//cout << l << " " << r << " " << mid << endl;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}
