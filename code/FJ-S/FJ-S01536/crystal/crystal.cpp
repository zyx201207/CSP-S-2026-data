#include <bits/stdc++.h>
using namespace std;

typedef long long intL;
const int maxn = 5e5 + 6;

intL n, m, a[maxn], s[maxn], ans = 1;

bool cmp(intL , intL);
bool check(int , int);

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1;i <= n;i++)
		s[i] = a[i] - a[i - 1];
	for(int i = 1;i <= n;i++){
		int l = i, r = n;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(check(i, mid))l = mid;
			else r = mid - 1;
		}
		ans = max(ans, 1ll * r - i + 1);
	}
	printf("%lld", ans + 1);
	return 0;
}

bool check(int l, int r){
	intL ret = 0;
	for(int i = l, w = 1;i <= r;i++, w++)
		ret += s[i] * w;
	return ret <= m;
}

bool cmp(intL x, intL y){
	return x < y;
}
