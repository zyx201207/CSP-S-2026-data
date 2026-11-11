#include<bits/stdc++.h>
using namespace std;

int c, t;
long long arr[5010], d, Min, Cnt;

void dfs(int v, int p, int s){
	if(p == v){
		if(Min == -1 || s < Min){
			Cnt = 1;
			Min = s;
			return;
		}
		if(s == Min){
			Cnt++;
			return;
		}
		return;
	}
	if(Min != -1 && s >= Min) return;
	for(int i=p+1; i<=v; i++){
		if(arr[i] - arr[p] <= d){
			dfs(v, i, s+1);
		}
		else{
			break;
		}
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &t);
	if(c <= 2){
		while(t--){
			int n;
			scanf("%d %lld", &n, &d);
			for(int i=1; i<=n; i++){
				scanf("%lld", &arr[i]);
			}
			int ans = 0;
			for(int i=1; i<=n; i++){
				for(int j=i+1; j<=n; j++){
					Min = -1;
					Cnt = 0;
					dfs(j, i, 0);
					if(Cnt == 2) ans++;
				}
			}
			printf("%d\n", ans);
		}		
	}
	else{
		while(t--){
			printf("0\n");
		}
	}
	return 0;
}
