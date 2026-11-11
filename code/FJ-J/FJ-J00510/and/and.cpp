#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], c[N], L, Maxn;
ll ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		Maxn = max(Maxn, a[i]);
	}
	L = n;
	ans = 0;
	for(int i = 30; i >= 0; i--){
		ll s = pow(2, i);
		if(s > Maxn)continue;
		int h = 0;
		for(int j = 1; j <= L; j++){
			if(s & a[j]){
				c[++h] = a[j];
			}
		}
		if(h < m)continue;
		else{
			for(int j = 1; j <= h; j++){
				a[j] = c[j];
			}
			L = h;
		}
	}
	ans = a[1];
	for(int i = 1; i <= L; i++){
		ans = ans & a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
