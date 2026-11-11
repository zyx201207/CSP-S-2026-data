#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn];
long long ans = 0;
char c[maxn];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)scanf("%d %c", a + i, c + i);
	int l = 1, r = n;
	while(l <= r) {
		if(c[l] != c[r])ans += min(a[l], a[r]);
		if(a[l] < a[r])a[r] -= a[l], l++;
		else if(a[l] > a[r])a[l] -= a[r], r--;
		else l++, r--;
	}
	printf("%lld", ans);
	return 0;
} 
