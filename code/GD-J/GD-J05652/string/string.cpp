#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n, a[N], ans = 0, l, r, i;
char c[N];
string s = "";
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (i = 1; i <= n; i++){
		scanf("%lld%s", &a[i], &c[i]);
	}
	l = 1, r = n;
	while (l < r){
		if (c[l] != c[r]){
			if (a[l] > a[r]){
				ans += a[r];
				a[l] = a[l] - a[r];
				a[r] = 0;
			}else if (a[l] < a[r]){
				ans += a[l];
				a[r] = a[r] - a[l];
				a[l] = 0;
			}else if (a[l] == a[r]){
				ans += a[l];
				a[l] = 0;
				a[r] = 0;
			}
		}else if (c[l] == c[r]){
			if (a[l] > a[r]){
				a[l] = a[l] - a[r];
				a[r] = 0;
			}else if (a[l] < a[r]){
				a[r] = a[r] - a[l];
				a[l] = 0;
			}else if (a[l] == a[r]){
				a[l] = 0;
				a[r] = 0;
			}
		}
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	printf("%lld", ans);
	return 0;
}
