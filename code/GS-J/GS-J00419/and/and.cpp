#include<bits/stdc++.h>
using namespace std;

int m, n, a[20010], l[20010], ma = -2147483647;
long long b[20010][51];

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int x = a[i];
		while(x != 0){
			b[i][l[++i]] = x % 2;
			x /= 2;
		}
	}

	for(int i = 1; i <= 51; i++){
		int x;
		for(int j = 1; j <= m; j++){
		 	for(int k = j; k <= n; k++){
				int q = b[j][i], p = b[k][i];
				int t = q & p;
				x += t * 2;
				x *= 2;
			}
		}
		ma = max(ma, x);
	}
	printf("%d", ma);
	return 0;
}
