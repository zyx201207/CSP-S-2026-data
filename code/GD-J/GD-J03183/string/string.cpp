#include<stdio.h>

constexpr int N = 2e5 + 10;
int n; int a[N], p; char c[N], s;
int l, r; long long ans;
inline int min(int x, int y){return x < y ? x : y;}

inline int read(){
	p = 0; s = getchar();
	while(s < '0' || s > '9') s = getchar();
	while(s >= '0' && s <= '9') p = (p << 1) + (p << 3) + (s ^ 48), s = getchar();
	return p;
}

int main(){
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	n = read(); l = 1; r = n;
	for(int i = 1; i <= n; i++){
		a[i] = read(); s = getchar(); while(s < 'a' || s > 'z') s = getchar(); c[i] = s;
	}
	int tmp, nxl, nxr;
	while(l < r){
		nxl = l; nxr = r;
		while((nxl == l || nxr == r) && l < r){
			tmp = min(a[l], a[r]); a[l] -= tmp; a[r] -= tmp;
			if(c[l] != c[r]) ans += tmp;
			if(!a[l]) l++;
			if(!a[r]) r--;
		}
	}
	printf("%lld", ans);
}
