#include<bits/stdc++.h>
using namespace std;

int c, t, n, sum, ans, cnt;
long long d, x[5001];

void dfs(int i, int s){
	if(i == s){
		if(sum < ans)
			ans = sum, cnt = 1;
		else
			if(sum == ans)
				cnt++;
		return;
	}
	for(int j = 1; j <= s - i; j++){
		if(x[i + j] - x[i] <= d){
			sum++;
			dfs(i + j, s);
			sum--;
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	for( ; t--; ){
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		int k = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++){
				sum = cnt = 0;
				ans = 1e9;
				dfs(i, j);
				if(cnt == 2)
					k++;
			}
		printf("%d\n", k);
	}
	return 0;
}
