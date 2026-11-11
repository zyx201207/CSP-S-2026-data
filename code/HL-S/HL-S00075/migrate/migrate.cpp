#include <bits/stdc++.h>
using namespace std;
const int max_n = 2000001;
int n;
long long int d, x[max_n], dp[301][301], ti[301][301];
namespace my_namespace {
	int main() {
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		int c, t;
		scanf("%d%d", &c, &t);
		
		for (int i = 1; i <= t; ++i) {
			long long int ans = 0;
			scanf("%d%lld", &n, &d);
			
			for (int i = 1; i <= n; ++i) {
				scanf("%lld", &x[i]);
			}
			
			for (int i = 1; i <= n; ++i) {
				
				for (int j = i + 1; j <= n; ++j) {
					dp[i][j] = LLONG_MAX / 2;
					ti[i][j] = 0;
				}
			}
			
			for (int k = 1; k < n; ++k) {
				
				for (int i = 1; i <= n - k; ++i) {
					int j = i + k;
					
					if (x[j] - x[i] <= d) {
						ti[i][j] = 1;
						dp[i][j] = 1;
					} else 
						for (int l = i + 1; l < j; ++l) {
							
							if (dp[i][l] + dp[l][j] < dp[i][j]) {
								ti[i][j] = 1;
								dp[i][j] = dp[i][l] + dp[l][j];
							} else if (dp[i][l] + dp[l][j] == dp[i][j]) {
								++ti[i][j];
							}
						}
				}
			}
			
			for (int i = 1; i <= n; ++i) {
				
				for (int j = i + 1; j <= n; ++j) {
					
					if (ti[i][j] == 2)
						++ans;
				}
			}
			
			printf("%lld\n", ans);
		}

		return 0;
	}
}
int main() {
	return my_namespace::main();
}
