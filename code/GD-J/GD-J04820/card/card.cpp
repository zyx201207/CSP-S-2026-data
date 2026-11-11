#include <bits/stdc++.h>
#define N 500050
using namespace std;
int m, n, i, j, k, b[N], a[N], f[N], he[N], c[N], l, r, y[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(f[a[i]]) b[f[a[i]]] = i;//上一个此元素位置的下一个相同元素位置是i 
		f[a[i]] = i, he[i] = i;//he[i]初始化一开始都可以出现i次 
//		printf("%d %d %d\n", b[2], a[i], he[i]);
	}
	for(i=1; i<=n; i++){
		c[i] += c[i-1], he[i] += c[i];//差分统计该位置出现次数 
//		printf("%d %d %d\n", i, c[i], he[i]);
		if(he[i] < 0|| !b[i]) continue;//后面没有相同的，或者本身在前面被消完后从不出现的 
		c[i] -= he[i], c[b[i]] += he[i], he[i] = 0; 
	}
	for(i=1; i<=n; i++) y[a[i]] += he[i];
	for(i=1; i<=m; i++){
		if(i == m) printf("%d", y[i]);
		else printf("%d ", y[i]);
	}
	return 0;
}
