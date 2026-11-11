#include<bits/stdc++.h>
using namespace std;
int n, w[1001];
int a[50010][501];
int t[50010][501];
int k[20010];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m;i++){
		scanf ("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf ("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++){
			scanf ("%d%d", &a[i][j], &t[i][j]);
		}
	}
	while(q--){
		int l, r;
		bool l1 = 1;
		scanf ("%d%d", &l, &r);
		int ans= 0;
		long long sum = 0;
		for (int i = 1; i <= n; i++){
			int t1 = 0;
			for (int j = 1; j <= k[i]; j++){
				if (l == r && j == 2){
					t1 = 1;
					sum += w[a[i][j]] + t[i][j];
					break;
				}
				if (a[i][j] == l && j == 1){
					if (l1){
						sum += w[a[i][j]] + t[i][j];
						l1 = 0;
						l = a[i][2];
						ans = t[i][2];
					}else{		
						sum += ans + t[i][j];
						l = a[i][2];
						ans = t[i][2];
					}	
				}
			}
			if (t1){
				break;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
