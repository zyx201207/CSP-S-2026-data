#include <iostream> 
#define int long long
#define N 200003
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 3) + (xxxx << 1) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
} 
struct node{
	int v; char c;
}a[N], b[N], c[N];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; ++i) a[i].v = read(), std :: cin >> a[i].c;
	int tot = 0;
	for(int i = n; i > 1; --i){
		if(a[i].c == a[i - 1].c) a[i - 1].v += a[i].v, a[i].v = 0;
	}
	for(int i = 1; i <= n; ++i){
		if(a[i].v) b[++tot] = a[i];
	}
	int result = 0, r = 1;
	for(int i = 1; i <= tot; ++i){
		while(b[i].v && i != tot - r + 1){
			int t = std :: min(b[i].v, b[tot - r + 1].v);
			if(b[i].c == b[tot - r + 1].c) ;
			else result += t;//, std :: cout << i << std :: endl;
			b[i].v -= t, b[tot - r + 1].v -= t;
			if(!b[tot - r + 1].v) ++r;
//			std :: cout << b[i].v << " " << i << std :: endl; 
		}
	}
	printf("%lld\n", result);
	return 0;	
}
