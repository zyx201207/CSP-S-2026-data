#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m, ans;
int a[N];

int num[N];

bool check(int x, int y) {
	int f = num[y] - num[x];
	f -= (a[y] - a[x]) * (x - 1);
//	cout << x << ' ' << y << ' ' << f << endl;
	return f <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);
	
	for(int i = 1 ; i <= n ; i ++) 
		num[i] = num[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	
	for(int i = 1 ; i <= n ; i ++) {
		int l = 1, r = i;
		int cnt = 0;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(check(mid, i)) {
				r = mid;
				cnt = mid;
			}
			else {
				l = mid + 1;
			}
		}
		ans = max(ans, (i - cnt + 1));
	}
	
	
	
	cout << ans;
	
	return 0;
}
