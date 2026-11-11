//贵阳市第一中学 谷佳鸿 GZ-S00130 
/*
crystal
双指针
先排序 
对于R
我们可以找到一个L
使得(r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn =5e5 + 5;
int n, a[maxn];
long long m, s[maxn];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int L = 1, R = 1, ans = 0;
	for(;R <= n; R++){
		while(1ll * (R - L + 1) * a[R] - (s[R] - s[L - 1]) > m) L++;
		ans = max(ans, R - L + 1);
	}
	printf("%d", ans);
	return 0;
}
