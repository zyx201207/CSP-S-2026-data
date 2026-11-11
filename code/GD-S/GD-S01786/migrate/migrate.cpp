#include <stdio.h>
int c, t, n, i, ans, j;
long long d, a[2000005], s[2000005];
int main(){
	freopen("migrate", "r", stdin);
	freopen("migrate", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(i=1; i<=n; i++) scanf("%lld", &a[i]);
		if(a[2] - a[1] < d && n >= 4 && a[2] - a[1] == d/2){
			printf("%d\n", (n - 4) + 1);
		}
		else{
			printf("%d\n", 0);
		}
	}
	return 0;
}
