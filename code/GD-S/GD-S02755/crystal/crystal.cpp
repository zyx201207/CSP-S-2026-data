#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], maxn = -1, h[10005][5005];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = -100; i <= 100; i++) {
		for (int j = 1;j <= n; j++) {
			h[100 + i][j] = i - a[j];
		}
	}
	for(int i = 0; i <= 200; i++) {
		sort(h[i] + 1, h[i] + n + 1);
	}
	for(int i = 0; i <= 200; i++) {
		int cnt = 0, sum = 0;
		for(int j = 1; j <= n; j++) {
			if(h[i][j] >= 0) {
				sum += h[i][j];
				cnt++;
				if (sum + h[i][j + 1] > m) break;
			}
		}
		maxn = max(maxn, cnt);
	}
	cout << maxn;
	return 0;
} 
