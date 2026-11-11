#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N][31], aa[N], q[N];
int my_sort(int l, int r, int w) {
	int t = 1;
	
	for(int i = l; i <= r; ++i) {
		if(a[q[i]][w] == 1) {
			swap(q[t], q[i]);
			
			t++;
		}
	}
	
	return t - 1;
} 
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		aa[i] = x;
		
		q[i] = i;
		
		for(int j = 0; j <= 30; ++j) {
			if(x & 1) a[i][j] = 1;
			x >>= 1;
		}
	}
	
	int l = 1, r = n;
	
	for(int i = 30; i >= 0; --i) {
		int len = my_sort(l, r, i);
		
		if(len < m) {
			continue;
		}
		else if(len == m) break;
		else if(len > m) r = len;
	}
	
	long long ans = aa[q[1]];
	
	for(int i = 2; i <= m; ++i) {
		ans = ans & aa[q[i]];
	}
	
	cout << ans << '\n';
}
