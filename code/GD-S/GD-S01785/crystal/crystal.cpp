#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n, m, ans;
ll a[N], s[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i);
	sort(a+1, a+1+n);
	for(int i=1; i<=n; ++i)
		s[i] = s[i-1]+a[i];

	ans = 1;
	for(int i=1,j=1; i<=n; ++i){//枚举最后要加到相等的数 
		while(j<=i && a[i]*(i-j)-s[i-1]+s[j-1]>m) ++j;
		ans = max(ans,i-j+1);
	}
	printf("%d\n", ans);
	return 0;
}
