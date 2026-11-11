#include <iostream> 
#include <bitset>
#define int long long
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 3) + (xxxx << 1) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
} 
int n, m, a[200003];
std :: bitset<200003> g[33], vis;
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), vis[i] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 30; ~j; --j){
			if(a[i] >= (1ll << j)) g[j][i] = 1, a[i] -= (1ll << j);
		}
	} 
	int result = 0;
	for(int i = 30; ~i; --i){
		std :: bitset<200003> t = (g[i] & vis);
		if(t.count() < m) continue;
		vis = t, result += (1ll << i);
	}
	printf("%lld\n", result);
	return 0;	
}
