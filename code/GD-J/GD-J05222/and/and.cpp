#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200001], ans = LLONG_MAX;
map <int, int> num;
int numb(int x){
	int y = 0;
	while (x){
		y += x % 2;
		x /= 2;
	}
	return y;
}
bool cmp(int a, int b){
	if (num[a] != num[b]){
		return num[a] > num[b];
	}
	else{
		return a > b;
	}
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		num[a[i]] = numb(a[i]);
		if (m == n){
			ans = (ans & a[i]);
		}
	}
	if (m == n){
		printf("%lld", ans);
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if (m == 1){
		printf("%lld", a[n]);
		return 0;
	}
	for (int i = n; i >= n - m + 1; i--){
		ans = (ans & a[i]);
	}
	printf("%lld", ans);
	return 0;
}
