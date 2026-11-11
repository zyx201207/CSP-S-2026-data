#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], ans;
bool b1;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n; ++i) {
		scanf("%d",&a[i]);
		if(a[i] != i - 1) {
			b1 = 1;
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	if(!b1) {
		ans = a[n - m];
		for(int i = n - m + 1; i <= n; ++i){
			ans = ans & a[i];
		}
		printf("%d", ans);
	}
	ans = a[n-1]&a[n];
	printf("%d", ans);
	return 0;
}
