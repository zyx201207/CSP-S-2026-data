#include <bits/stdc++.h>
using namespace std;
const int N = 500050;
int n, m, i, j, k, ans;
long long c, a[N], s[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &c);
	for(i=1; i<=n; i++) scanf("%lld", a+i);
	sort(a+1, a+n+1);
	for(j=i=1; i<=n; i++){
		s[i] = s[i-1]+a[i];
		while(j<i && a[i]*(i-j+1)-(s[i]-s[j-1])>c) j++;
		ans = max(ans, i-j+1);
	}
	printf("%d\n", ans);
	return 0;
}
