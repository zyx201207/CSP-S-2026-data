#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long LL;
const int N = 2e5 + 5;
int n, a[N], m, j, ans;
bool cmp(int x, int y){
	return (x >> j & 1) > (y >> j & 1);
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int k = n;
	for (j = 29; j >= 0; j--){
		sort(a + 1, a + 1 + k, cmp);
		if (a[m] >> j & 1){
			while (!(a[k] >> j & 1)) k--;
			ans |= 1 << j;
		}
	}
	printf("%d", ans);
	return 0;
}
