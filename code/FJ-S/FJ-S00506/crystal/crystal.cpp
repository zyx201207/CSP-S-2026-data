#include <bits/stdc++.h> 
#define i64 long long 
using namespace std; 
const int N = 5e5 + 5; 
int n, ans; 
i64 m, a[N], b[N], pre[N], ppre[N];      
int main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	scanf("%d %lld", &n, &m); 
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); 
	} 
	sort(a + 1, a + n + 1); 
	for(int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1]; 
	}  
	ans = 1; 
	if(n <= 5000) {
		for(int i = 2; i <= n; i++) { 
			i64 cnt = 0; 
			int tmp = 0;  
			for(int j = i; j >= 1; j--) {
				if(cnt + a[i] - a[j] > m) break; 
				cnt += a[i] - a[j];  
				tmp ++;  
			} 
			ans = max(ans, tmp); 
		} 
		printf("%d\n", ans); 
		return 0; 
	} else {
		int tmp = 1; 
		for(int i = 2; i <= n; i++) { 
			pre[i] = pre[i - 1]; 
			ppre[i] = ppre[i - 1]; 
			if(a[i] != a[i - 1]) {
				pre[i] += b[i]; 
				ppre[i] += b[i] * (i - 1); 
				tmp = 1; 
			} else {
				tmp++; 
			}
			int l = 1, r = i, pos = i; 
			while(l <= r) {
				int mid = (l + r) / 2; 
				i64 tmp = ppre[i] - ppre[mid] - (pre[i] - pre[mid]) * (mid - 1); 
				//cerr << mid << ' ' << i << ' ' << tmp << endl; 
				if(tmp <= m) pos = mid, r = mid - 1; 
				else l = mid + 1; 
			} 
			//cerr << i << ':' << ppre[i] << endl; 
			//cerr << i << ' ' << pos << endl; 
			ans = max(ans, i - pos + 1); 
		} 
		printf("%d\n", ans); 
	}
	return 0; 
}
