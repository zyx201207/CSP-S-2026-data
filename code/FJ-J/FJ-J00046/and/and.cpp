# include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 55;
int a[N];
int sum;
int cnt = 0;
int n, m;

void dfs (int x, int t, int val) {
	if (x <= n && t == m) {
		cnt = max (cnt, val);
		return;
	} else if (x > n || t > m) {
		return;
	}
	if (t <= m){
		dfs (x + 1, t + 1, val & a[x]);
	}
	
	dfs (x + 1, t, val);
}
// 不不不，这无疑是难绷的 

int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	ios::sync_with_stdio (false);
	cin.tie (0);
	
	cin >> n >> m;	
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			sum = a[i];
		} else {
			sum &= a[i];
		}
	}
	
	sort (a + 1, a + 1 + n, greater <int> ());
	
	if (n <= 20 && m <= 20) {
		for (int i = 1; i <= n; i++) {
			dfs (i + 1, 1, a[i]);
		}
		
		cout << cnt << endl;
		return 0;
	}
	
	if (m == 1) {
		cout << a[1] << endl;
		return 0;
	} 
	
	if (m == n) {
		cout << sum << endl;
		return 0;
	} 
	
	if (m == n - 1) {
		int maxn = 0;
		for (int i = 1; i <= n; i++) {
			maxn = max (maxn, sum & a[i]);
		}
		
		cout << maxn << endl;
		return 0;
	}
	
	if (m == 2) {
		int maxn = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int t = a[i] & a[j];
				maxn = max (maxn, t);
			}
		}
		
		cout << maxn << endl;
		return 0;
	}
	
	int ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans &= a[i];
	}
	
	cout << ans << endl;
	return 0;
} 

// 52春意 
