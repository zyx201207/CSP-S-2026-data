#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, l, maxn, a[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	l = 1, maxn = 1;
	for (int i = 2; i <= n; i++){
		m -= (i - l) * (a[i] - a[i - 1]);
		while (m < 0){
			m += a[i] - a[l];
			l++;
		}
		maxn = max(maxn, i - l + 1);
	}
	printf("%lld", maxn);
	return 0;
}
