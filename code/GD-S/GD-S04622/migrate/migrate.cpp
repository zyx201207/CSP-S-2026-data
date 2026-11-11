#include <cstdio>
#include <cstring>
#define N 405
using namespace std;
int i, j, k, w, n, m, c, cnt, T, d, ans, f;
int a[N], p[N][N][N];
int dfs(int x, int y, int s){
	if(x > y) return 0;
	if(s == 0) return x == y; 
	int &o = p[x][y][s];
	if(~o) return o;
	o = 0;
	for(int i=x+1; a[i]-a[x]<=d; i++){
		o += dfs(i, y, s-1);
	}
	return o;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		if(c >= 7){
			puts("0");
			continue;
		}
		ans = 0;
		scanf("%d%d", &n, &d);
		for(i=1; i<=n; i++) scanf("%d", &a[i]);
		for(i=1; i<=n; i++){
			for(j=i+2; j<=n; j++){
				w = k = i, cnt = 1;
				while(k<j){
					k++;
					if(a[k] - a[w] > d) cnt ++, w = k-1;
				}
				if(cnt >= 2){
					memset(p, -1, sizeof(p));
					if(dfs(i, j, cnt) == 2) ans ++;
				}
			}
		} 
		printf("%d\n", ans);
	}
	return 0;
}
