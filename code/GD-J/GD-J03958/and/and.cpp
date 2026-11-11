#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N],sum[N];
bool vis[N];
int n,m;
long long dfs(int depth,int x) {
	if (m == depth) return a[x];
	vis[x] = true;
	long long best = 0;
	for (int i = 1;i <= n;i ++) {
		if (vis[i] == false) {
			best = max(best,(a[x]&dfs(depth+1,i)));
		} 
	}
	vis[x] = false;
	return best;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d %lld",&n,&m,&a[1]);
	
	sum[1] = a[1];
	long long mx = -1;
	for (int i = 2;i <= n;i ++) {
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1] & a[i];
		mx = max(mx,a[i]);
	}
	if (n == m) {
		printf("%lld",sum[n]);
		return 0;
	}
	if (m == 1) {
		printf("%lld",mx);
		return 0;
	}
	if (m == 2) {
		long long ans = 0;
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j < i;j ++) {
				ans = max(ans,(a[i]&a[j]));
			}
		}
		printf("%lld",ans);
		return 0;
	}
	long long ans = 0;
	for (int i = 1;i <= n;i ++) {
		ans = max(ans,dfs(1,i));
	}
	printf("%lld",ans);
	return 0;
} 
