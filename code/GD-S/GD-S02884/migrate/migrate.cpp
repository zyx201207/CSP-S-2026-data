#include<stdio.h>

constexpr int N = 5e6 + 10;
using ll = long long;
int n, F[N], f; ll a[N], d, ans, p, id; char c, A[20];

inline ll read(){
	p = 0; f = 1; c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
	return p * f;
}
inline void write(ll x){
	if(!x){putchar('0'); putchar('\n'); return;}
	id = 0;
	while(x) A[++id] = x % 10, x /= 10;
	while(id) putchar(A[id--] ^ 48);
	putchar('\n');
}

void sol(){
	n = read(); d = read();
	for(int i = 1; i <= n; i++) a[i] = read(), F[i] = 0;
	int j, zl, dd, cnt, cnt1, cnt2; a[n + 1] = 4e18;
	for(int i = 1; i <= n; i++) if(!F[i]){
		j = i; dd = a[i] + d; F[i] = 0; cnt = 1;
		do{zl = 0; while(a[j] <= dd) F[j++] = cnt, zl++; dd = a[j - 1] + d; cnt++;}while(zl);
	}
	F[0] = 1;
	for(int i = 1; i <= n; i++){
		j = i + 1; cnt1 = 1; cnt2 = 0;
		
	}
	write(ans); ans = 0;
}

int main(){
	int T;
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	T = read(); T = read();  while(T--) sol();
}
