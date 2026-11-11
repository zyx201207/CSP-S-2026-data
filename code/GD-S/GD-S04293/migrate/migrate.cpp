#include <bits/stdc++.h>
using namespace std;

int test, t;
long long n, fly, s[2000005] = {};

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d%d", &test, &t);
	while(t--){
		scanf("%lld%lld", &n, &fly);
		for(int i = 1;i <= n; i++)  scanf("%lld", &s[i]);
		if(test == 11 || test == 12){
			if(n == 1){
				printf("0\n");
				continue;
			}
			long long times = fly / (s[2] - s[1]);
			if(times <= 1){
				printf("0\n");
				continue;
			}
			long long ans = n - 2 * times + 1;
			if(ans < 0)  printf("0\n");
			else printf("%lld\n", ans);
		}
	}
	
	
	return 0;
}
