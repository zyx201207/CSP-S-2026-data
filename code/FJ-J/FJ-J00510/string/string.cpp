#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], lw, rw, l, r;
ll ans;
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cin >> c[i];
	}
	l = 0;
	lw = 1;
	r = 0;
	rw = n;
	while(lw < rw){
		if(a[lw] - l > a[rw] - r){
			if(c[lw] != c[rw]){
				ans += a[rw] - r;
			}
			l += a[rw] - r;
			rw--;
			r = 0;
		}else if(a[lw] - l < a[rw] - r){
			if(c[lw] != c[rw]){
				ans += a[lw] - l;
			}
			r += a[lw] - l;
			lw++;
			l = 0;
		}else{
			if(c[lw] != c[rw]){
				ans += a[lw] - l;
			}
			lw++;
			rw--;
			l = r = 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
