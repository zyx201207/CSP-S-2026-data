#include <bits/stdc++.h>
using namespace std;

const int MXN = 5e5 + 1;

int n, ns;
long long m, a[MXN];
long long sum[MXN];

long long read(){
	long long x = 0;
	int f = 1;
	char c = getchar();
	for(;c < '0' || c > '9';c = getchar())
		if(c == '-') f = -f;
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x * f;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int i, j;
	n = read();
	m = read();
	for(i = 1;i <= n;++i) a[i] = read();
	sort(a + 1, a + n + 1);
	for(i = 1;i <= n;++i) sum[i] = sum[i - 1] + a[i];
	for(i = 1, j = 0;i <= n;++i){
		for(;a[i] * (i - j) - (sum[i] - sum[j]) > m;) ++j;
		ns = max(ns, i - j);
	}
	printf("%d", ns);
	return 0;
}
