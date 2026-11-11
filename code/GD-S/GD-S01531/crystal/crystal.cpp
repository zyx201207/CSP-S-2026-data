#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define int long long
int n, m, a[1000010], s[1000010];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int Ans = 0;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j <= i && a[i] * (i - j + 1) - (s[i] - s[j - 1]) > m) j++;
		Ans = max(Ans, i - j + 1);
	}
	printf("%lld\n", Ans);
	return 0;
}
