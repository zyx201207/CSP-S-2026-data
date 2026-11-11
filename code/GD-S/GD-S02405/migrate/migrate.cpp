#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[10001][10001];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf ("%d%d", &c, &t);
	while(t--){	
		int n, m;
		scanf ("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			scanf ("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (i != j){
					b[i][j] = abs(a[j] - a[i] + m - 1) / m;
				}else{
					b[i][j] = 0;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++){
			int t = 0, ans = 1e9;
			for (int j = 1; j <= i - 1; j++){
				if (b[j][1] + b[j][i] < ans){
					ans = min(b[j][1] + b[j][i], ans);
					t = 1;
				}
				if (b[j][1] + b[j][i] == ans){
					t++;
				}
			}
			if (t == 2){
				sum++;
				printf("%d\n", i);
			}
		}
		printf("%d\n", sum); 
	}
	return 0;
}
