#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
char ch[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %c", &a[i], &ch[i]);
	}
	ll l = 1, r = n, cnt = 0;
	while(l < r) {
		if(ch[l] == ch[r]) {
			if(a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else if(a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else {
				l++, r--;
			}
		} else {
			if(a[l] < a[r]) {
				a[r] -= a[l];
				cnt += a[l];
				l++;
			} else if(a[l] > a[r]) {
				a[l] -= a[r];
				cnt += a[r];
				r--;
			} else {
				cnt += a[r];
				l++, r--;
			}
		}
	}
	printf("%lld", cnt);
	return 0;
}
