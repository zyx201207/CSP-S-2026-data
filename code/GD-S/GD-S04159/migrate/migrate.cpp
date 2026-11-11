//migrate
#include <stdio.h>
int c, _, n;
long long floyd[5145][5145], x[2145141], f2[5145][5145];
unsigned long long d;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &_);
	while(_--) {
		scanf("%d %llu", &n, &d);
		int i, j;
		if(n <= 5000) {
			for(i = 1; i <= n; i += 1) {
				for(j = 1; j <= n; j += 1) floyd[i][j] = 0xFFFFFFFFLL, f2[i][j] = 0;
			}
		}
		for(i = 1; i <= n; i += 1) {
			scanf("%lld", &x[i]);
			if(n <= 5000) {
				for(j = i - 1; j >= 1; j -= 1) {
					if(x[i] < 0 && x[j] < 0) {
						if((unsigned long long)(-x[j]) - (unsigned long long)(-x[i]) <= d) {
							floyd[j][i] = 1;
							f2[j][i] = 1;
						}
						else break;
					}
					else if(x[j] < 0) {
						if(x[i] + (unsigned long long)(-x[j]) <= d) {
							floyd[j][i] = 1;
							f2[j][i] = 1;
						}
						else break;
					}
					else {
						if(x[i] - x[j] <= d) {
							floyd[j][i] = 1;
							f2[j][i] = 1;
						}
						else break;
					}
				}
			}
		}
		/*for(i = 1; i <= n; i += 1) {
			for(j = 1; j <= n; j += 1) {
				printf("%2d ", floyd[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");*/
		if(n <= 5000) {
			int k, cnt = 0;
			for(i = 1; i <= n; i += 1) {
				for(j = i + 1; j <= n; j += 1) {
					for(k = i + 1; k < j; k += 1) {
						if(floyd[i][j] < n && floyd[i][j] == floyd[i][k] + floyd[k][j] && floyd[i][k] != 0xFFFFFFFFLL && floyd[k][j] != 0xFFFFFFFFLL) {
							f2[i][j] += f2[i][k] * f2[k][j];
						}
						else if(floyd[i][k] != 0xFFFFFFFFLL && floyd[k][j] != 0xFFFFFFFFLL && floyd[i][j] > floyd[i][k] + floyd[k][j]) {
							floyd[i][j] = floyd[i][k] + floyd[k][j];
							f2[i][j] = f2[i][k] * f2[k][j];
						}
					}
					if(f2[i][j] == 2) cnt += 1;
				}
			}
			printf("%d\n", cnt);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
