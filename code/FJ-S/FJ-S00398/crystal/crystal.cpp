// 2026 CSP-S A ( crystal )
#include <bits/stdc++.h>
using namespace std;
namespace kqpkao_namespace{

typedef long long ll;
const int N = 5e5 + 5;
ll m, a[N], s[N];
int n, ans;
int k_main(){
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	s[0] = 0;
	ans = 0;
	for (int i = 1, j = 0; i <= n; ++i){
		s[i] = s[i - 1] + a[i];
		while (j < i && s[i] - s[j] + m < a[i] * (i - j)){
			++j;
		}
		ans = max(ans, i - j);
	}
	printf("%d\n", ans);
	return 0;
}

}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int k_ret = kqpkao_namespace::k_main();
	return k_ret;
}
