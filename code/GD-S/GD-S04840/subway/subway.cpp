#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c, n, m, d, q, w[500005], a[1005][1005], t[1005][1005], k[505], f[1005][1005], l[500005][25], cnt[500005], T; 
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= 1000; i++){
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	if(c <= 11){
		for(int i = 1; i <= n; i++){
			scanf("%d", &k[i]);
			for(int j = 1; j <= k[i]; j++){
				scanf("%d%d", &a[i][j], &t[i][j]);
				for(int k = 1; k < j; k++){
					f[a[i][j]][a[i][k]] = f[a[i][k]][a[i][j]] = min(f[a[i][j]][a[i][k]], t[i][j] + t[i][k]);
				}
			}
		}
		for(int k = 1; k <= m; k++){
			for(int i = 1; i <= m; i++){
				for(int j = 1; j <= m; j++){
					if(f[i][j] > f[i][k] + f[j][k])f[i][j] = f[i][k] + f[j][k];
				}
			}
		}
		while(q--){
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", f[x][y] + w[x] + w[y]);
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			scanf("%d", &k[i]);
			for(int j = 1; j <= k[i]; j++){
				int a;
				scanf("%d%d", &a, &T);
				l[a][++cnt[a]] = i;
			}
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= cnt[i]; j++){
				for(int k = 1; k < j; k++){
					f[l[i][j]][l[i][k]] = f[l[i][k]][l[i][j]] = 1;
				}
			}
		}
		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(f[i][j] > f[i][k] + f[j][k])f[i][j] = f[i][k] + f[j][k];
				}
			}
		}
		while(q--){
			int x, y;
			scanf("%d%d", &x, &y);
			int ans = 2e9;
			for(int i = 1; i <= cnt[x]; i++){
				for(int j = 1; j <= cnt[y]; j++){
					ans = min(ans, f[l[x][i]][l[y][j]]);
				}
			}
			ans++;
			printf("%d\n", w[x] + w[y] + ans * 2 * T);
		}
	}
} 
