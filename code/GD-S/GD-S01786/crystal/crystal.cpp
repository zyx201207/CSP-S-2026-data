#include <bits/stdc++.h>
using namespace std;
int n;
long long i, j, ans, k, m, a[500005], sum, tmp;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(i=j=1; i<=n; i++){
		if(i != 1) sum -= a[j] - a[i-1];
		while(sum+(a[j+1] - a[j])*(j-i) <= m && j <= n){
			sum += (a[j] - a[j-1]) * (j - i);
			if(sum > m){
				sum -= (a[j] - a[j-1]) * (j - i);
				j--;
				break;
			}
			if(sum + (a[j+1] - a[j])*(j-i) <= m) j++;
		}
		if(j > n) j = n;
		ans = max(ans, j-i+1);
	}
	printf("%d", ans);
	return 0;
}
