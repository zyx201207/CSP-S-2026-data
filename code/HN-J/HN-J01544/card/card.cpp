#include<bits/stdc++.h>
using namespace std;
int n, m, a[500001], dp[500001], lst[300001], sum[500001];
long long ans[300001];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for(int i = n; i >= 1; i--){
		if(lst[a[i]] == 0)dp[i] = lst[a[i]] = i;
		else dp[i] = lst[a[i]];
	}
	fill(sum + 1, sum + n + 1, 1);
	for(int i = 1; i <= n; i++){
		if(dp[i] < n)sum[dp[i] + 1] += sum[i];
		ans[a[i]] += sum[i];
	}
	for(int i = 1; i <= m; i++)printf("%lld ", ans[i]);
	return 0;
}
