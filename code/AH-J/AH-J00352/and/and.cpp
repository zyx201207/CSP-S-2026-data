#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N][40], count1[40], n, m, x[N], pos = 1;
long long ans;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	for(int i = 1; i <= n; i++){
		int xx = x[i], y = 1;
		while(xx){
			a[i][y] = xx % 2;
			count1[y] += xx % 2;
			xx /= 2;
			y++;
		}
	}
	for(int i = 35; i >= 1; i--){
		ans *= 2;
		if(count1[i] >= m){
			ans++;
			for(; pos <= n - count1[i]; pos++) for(int j = 1; j <= 35; j++) count1[j] -= a[pos][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
