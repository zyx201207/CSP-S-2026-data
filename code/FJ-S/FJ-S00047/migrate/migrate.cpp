#include<bits/stdc++.h>
using namespace std;

int n, c, T;
long long x[2000005], d, wq[2000005], wh[2000005], lst[2000005], dp[2000005], fa[2000005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c == 11 || c == 12){
		while(T--){
			scanf("%d%lld", &n, &d);
			for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
			for(int i = 2; i <= n; i++){
				int l = 1, r = i - 1, mb = 0;
				while(l <= r){
					int mid = l + r >> 1;
					if(x[i] - x[mid] <= d) mb = mid, r = mid - 1;
					else l = mid + 1;
				}
				lst[i] = mb;
			}
			long long ans = 0;
			dp[1] = 0;
			fa[1] = 1;
			int flag;
			for(int i = 2; i <= n; i++){
				flag = i;
				if(x[i] - x[1] > d) break;
				dp[i] = 1;
				fa[i] = 1;
			}
			for(int i = flag; i <= n; i++){
				if(!lst[i]) break;
				dp[i] = dp[lst[i]] + 1;
				fa[i] = fa[lst[i]];
				for(int j = lst[i] + 1; j <= lst[i] + 2; j++){
					if(j >= i) break;
					if(dp[i] != dp[j] + 1) break;
					fa[i] += fa[j];
				}
			}
			for(int i = 1; i <= n; i++){
				if(fa[i] == 2) ans += (1ll * n - 1ll * i + 1ll);
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
	while(T--){
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		for(int i = 2; i <= n; i++){
			int l = 1, r = i - 1, mb = 0;
			while(l <= r){
				int mid = l + r >> 1;
				if(x[i] - x[mid] <= d) mb = mid, r = mid - 1;
				else l = mid + 1;
			}
			lst[i] = mb;
			//printf("%d ", lst[i]);
		}
		//printf("\n");
		int ans = 0;
		for(int i = 1; i <= n; i++){
			dp[i] = 0;
			fa[i] = 1;
			int flag;
			for(int j = i + 1; j <= n; j++){
				flag = j;
				if(x[j] - x[i] > d) break;
				dp[j] = 1;
				fa[j] = 1;
			}
			if(x[n] - x[i] <= d) continue;
			for(int j = flag; j <= n; j++){
				if(!lst[j]) break;
				dp[j] = dp[lst[j]] + 1;
				fa[j] = fa[lst[j]];
				for(int k = lst[j] + 1; k <= lst[j] + 2; k++){
					if(k >= j) break;
					if(dp[j] != dp[k] + 1) break;
					fa[j] += fa[k];
				}
				if(fa[j] == 2) ans++;
			}
			//for(int j = i; j <= n; j++) printf("%d ", fa[j]);
			//printf("\n");
		}
		printf("%d\n", ans);
	}
	return 0;
}
