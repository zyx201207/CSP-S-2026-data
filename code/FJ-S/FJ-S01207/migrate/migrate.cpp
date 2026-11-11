#include<bits/stdc++.h>
using namespace std;
int C, t, n, d;
long long x[2000009];
int st[2000009];
int ans;
struct D{
	int stp, tot;
	void init(){
		stp = 0x3f3f3f3f;
		tot = 0;
	}
	void update(int a){
		if(a == stp){
			tot++;
			return;
		}
		if(a < stp){
			tot = 1;
			stp = a;
			return;
		}
	}
}A;
void dfs(int p, int e, int stps){
	if(p == e){
		A.update(stps);
		return;
	}
	for(int i=1; i<=st[p]; i++){
		dfs(p + i, e, stps + 1);
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &C, &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(int i=1; i<=n; i++){
			scanf("%lld", &x[i]);
		}
		if(n == 1){
			puts("0");
			continue;
		}
		if(C <= 10){
			for(int i=1; i<=n; i++){
				st[i] = upper_bound(x + i, x + n + 1, x[i] + d) - (x + i + 1);
			}
			ans = 0;
			for(int i=1; i<=n; i++){
				for(int j=i+1; j<=n; j++){
					A.init();
					dfs(i, j, 0);
					if(A.tot == 2){
						ans++;
					}
				}
			}
			printf("%d\n", ans);
		}else{
			puts("0");
		}
	}
	return 0;
}

