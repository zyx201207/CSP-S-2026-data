#include <iostream>
#include <algorithm>
#define int long long
#define N 500003
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 1) + (xxxx << 3) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
}
int n, m, a[N], s[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read(); 
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	int result = 0;
	for(int i = 1; i <= n; ++i){
		int l = 0, r = i + 1;
		while(l < r - 1){
			int mid = (l + r >> 1);
			if(a[i] * (i - mid + 1) - s[i] + s[mid - 1] <= m) r = mid;
			else l = mid;
		}
		result = std :: max(result, i - r + 1);
	}
	printf("%lld\n", result);
	return 0;
}

