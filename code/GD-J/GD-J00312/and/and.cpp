#include <bits/stdc++.h>
#define ll long long
const int p = 2e5 + 1;
using namespace std;
int n, m, a[p];
int f[p][32], u[p]; // 第i个数第j个位 （bool） 
ll d[32], ans;
int main () {
	freopen("and5.in", "r", stdin);
	freopen("and.out", "w", stdout);	
	scanf("%d%d", &n, &m);
	d[0] = 1;	
	for (int i = 1; i <= 31; i++) 
		d[i] = d[i - 1] * 2;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	int l = upper_bound(d + 1, d + 31 + 1, a[1]) - d - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= l; j++)
			f[i][j] = a[i] & d[j];		
	for (int i = l; i; i--) {
		int k = 0;
		for (int j = 1; j <= n; j++) {
			if (f[j][i]) u[++k] = j; 
			if (k == m) {
				ans = a[u[1]];
				for (int b = 2; b <= k; b++)
					ans &= 1ll * a[u[b]];
				printf("%lld", ans); return 0; 
			} 
		}
	} puts("0");  
}
