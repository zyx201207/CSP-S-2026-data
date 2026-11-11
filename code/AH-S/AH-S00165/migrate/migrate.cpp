#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
long long a[N];
inline long long read() {
	long long x = 0, f = 1;
	
	char ch = getchar();
	
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	
	return x * f;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &c, &t);
	
	while(t--) {
		int n; long long d;
		scanf("%d", &n);
		scanf("%lld", &d);
		
		for(int i = 1; i <= n; ++i) {
			a[i] = read();
		}
		
		long long ans = 0;
		
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				if(a[j] - a[i] <= d) continue;
				
				int pos1 = upper_bound(a + i, a + j, a[i] + d) - a - 1;
				int pos2 = lower_bound(a + i, a + j, a[j] - d) - a;
				
				if(pos1 - pos2 == 1) {
					int l = 1, r = 1;
					
					for(int k = i - 1; k >= 1; --k) {
						if(a[k] + d >= a[k + 1] && a[k] + d < a[k + 2]) l++;
						else break; 
					}
					
					for(int k = j + 1; k <= n; ++k) {
						if(a[k] - d <= a[k - 1] && a[k] - d > a[k - 2]) r++;
						else break;
					}
					ans += (l * r);
				}
			}
		}
		
		printf("%lld\n", ans);
	}
	
}
