#include <bits/stdc++.h>
#define qwq std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define int long long

inline int read(){
	int x = 0, f = 1; char h = getchar();
	while(!isdigit(h)){ if(h == '-') f = -f; h = getchar(); }
	while(isdigit(h)){ x = x * 10 + (h ^ 48); h = getchar(); }
	return x * f;
}

const int N = 5e5 + 10;
int n, m, ans, a[N];
int q[N], head, tail;

int32_t main(){
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + 1 + n);
	head = 1, tail = 0;
	for(int i = 1, val = 0; i <= n; ++i){
		val += (a[i] - q[tail]) * (tail - head + 1);
		while(head <= tail && val > m) val -= (a[i] - q[head++]);
		q[++tail] = a[i], ans = std::max(ans, tail - head + 1);
	}
	printf("%lld", ans);
	return 0;
}
/*
“ª—€√Î°£
14:43 100pts
*/
