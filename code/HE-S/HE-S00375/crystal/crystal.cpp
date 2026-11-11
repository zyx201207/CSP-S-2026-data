#include<iostream>
#include<algorithm>
#define int long long
const int N = 5e5 + 5;
int n,a[N],m,ans,sum[N];
void in(int & n) {
	int res = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f *= -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')
		res = res * 10 + ch - '0',ch = getchar();
	n = res;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	in(n),in(m);
	for(int i = 1; i <= n; i ++) in(a[i]);
	std::sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + a[i];
	int j = 1;
	for(int i = 1; i <= n; i ++) {
		while(a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m && j < i) j ++;
		ans = std::max(ans,i - j + 1);
	}
	printf("%lld\n",ans);
}
