#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, d[500001], f[500001], a[500001], t[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		d[i] = abs(a[i] - a[i - 1]);
	}
    for(int i = 1; i <= n; i++){
        f[i] = d[i] * (i - 1) + f[i - 1];
	}
	for(int i = 1; i <= n; i++)t[i] = t[i - 1] + d[i];
	ll res = 0, l = 1, r = n, ll = 0, rr = 0;
	for(int i = 1; i <= n; i++){
		if(f[i] <= m)res = i;
	}
	printf("%lld", res);
	return 0;
}
