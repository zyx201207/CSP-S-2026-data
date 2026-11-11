#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N = 2e5 + 5;
int n, a[N], sum;
char c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		cin >> c[i];
		sum += a[i];
	}
	sum >>= 1;
	int ans = 0, sl = 0, sr = 0;
	for (int l = 1, r = n; l <= r; l++){
		sl += a[l];
		if (sl > sum) sl = sum;
		while (sr < sl){
			sr += a[r];
			if (c[l] != c[r]){
				if (sr > sl) ans += sl - (sr - a[r]);
				else ans += a[r];
			}
			if (sr > sl){
				sr -= a[r];
				a[r] -= sl - sr;
				sr = sl;
				continue;
			}
			r--;
		}
	}
	printf("%lld", ans);
	return 0;
}
