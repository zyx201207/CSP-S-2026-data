#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 2e5 + 10;

int n, idx;
ll a[N];
char c[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		ll num;
		char ch;
		scanf("%d %c", &num, &ch);
		if (!idx || c[idx] != ch) idx ++, c[idx] = ch, a[idx] = num;
		else a[idx] += num;
	}
	
	ll res = 0;
	int i = 1, j = idx;
	while (i < j) {
		if (c[i] == c[j]) {
			if (a[i] > a[j]) a[i] -= a[j], j --;
			else a[j] -= a[i], i ++;
		}
		else {
			if (a[i] > a[j]) a[i] -= a[j], res += a[j], j --;
			else a[j] -= a[i], res += a[i], i ++;
		}
	}
	printf("%lld", res);
	
	return 0;
} 
