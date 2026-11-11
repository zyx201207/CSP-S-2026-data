//GZ-J00410 肖耿毅 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long a[200050];
void dfs(long long i, long long j, long long num) {
	//cout<<i<<j<<num<<endl;
	if(j == m) {
		ans = max(ans, num);
		return;
	}
	if(i == n && j < m) return;
	if(i + (m - j) > n) return;
	for(int I = i + 1; I <= n; I++) {
		//cout<<num<<" "<<a[I]<<" "<<(num & a[I])<<endl;
		dfs(I, j + 1, num & a[I]);
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++)
		dfs(i, 1, a[i]);
	printf("%lld\n", ans);
	return 0;
}
