#include<stdio.h>

constexpr int N = 5e5 + 10;
int n, m, top, a[N], q[N], ans[N], to[N], vis[N], side[N], V[N];

int id, answer[10], p; char c;
inline int read(){
	p = 0; c = getchar();
	while(c > '9' || c < '0') c = getchar();
	while(c >= '0' && c <= '9') p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
	return p;
}
inline void write(int x){
	if(!x){putchar('0'); putchar(' '); return;}
	id = 0;
	while(x) answer[++id] = x % 10, x /= 10;
	while(id) putchar(answer[id--] ^ 48);
	putchar(' ');
}

int main(){
	freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = n; i; i--){
		if(!vis[a[i]]) vis[a[i]] = i;
		to[i] = vis[a[i]]; side[to[i]]++;
	}
	for(int i = 1; i <= n; i++) if(to[i] == i) ans[a[i]] += side[i], side[to[i + 1]] += side[i];
	for(int i = 1; i <= m; i++) write(ans[i]);
}
