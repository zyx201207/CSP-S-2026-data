#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n, ans = 0;
long long a[500005], sum[500005], m;
long long need(int l, int r){
	return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 0, r = i + 1;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if(need(mid, i) > m)l = mid;
			else r = mid;
		}
		ans = max(ans, i - r + 1);
	}
	printf("%d", ans);
	return 0;
} 
