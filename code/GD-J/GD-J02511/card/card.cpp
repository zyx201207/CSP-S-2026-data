#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	scanf ("%d%d", &n, &m);
	int a[10001], b[10001], c[10001];
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++){
		scanf ("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++){
		int pos = 0;
		for (int j = i; j <= n; j++){
			int t = 0, l = 0;
			for (int k = 1; k <= pos; k++){
				if (b[k] == a[j]){
					t = 1;
					l = k;
					break;
				}
			}
			if (!t){
				b[++pos] = a[j];
			}else{
				pos = l;
				b[pos] = a[j];
			}
		}
		for (int j = 1; j <= pos; j++){
			c[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
