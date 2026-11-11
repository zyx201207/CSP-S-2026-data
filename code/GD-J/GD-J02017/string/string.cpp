#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;
int a[N];
char c[N];
ll pre[N], suf[N];
ll lis[N << 1];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d %c", a + i, c + i);
		pre[i] = pre[i - 1] + a[i], lis[i] = pre[i];
	}
	for(int i = n;i >= 1;i--)suf[i] = suf[i + 1] + a[i], lis[i + n] = suf[i];
	sort(lis + 1, lis + (n << 1) + 1);
	int lnt = unique(lis + 1, lis + (n << 1) + 1) - lis - 1;
	ll L = pre[n];
	int pl = 0, pr = n + 1;
	ll ans = 0;
	for(int i = 1;i <= lnt && lis[i] <= (L >> 1);i++){
		while(pre[pl] < lis[i])pl++;
		while(suf[pr] < lis[i])pr--;
		if(c[pl] != c[pr])ans += lis[i] - lis[i - 1]; 
	}
	printf("%lld", ans); 
	return 0;
}
/*

3
2 a
2 b
1 c
*/
