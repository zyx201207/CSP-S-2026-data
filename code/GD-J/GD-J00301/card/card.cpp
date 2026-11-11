#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, a[N], b[N], sum[M], id[M];
bool vis[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		b[id[a[i]]] = i;
		id[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		int num = 0;
		if (vis[i]) continue;
		for (int j = i; j <= n; ){
			if (!vis[j]) num++;
			vis[j] = 1;
			if (b[j]){
				j = b[j];
				continue;
			}
			sum[a[j]] += num;
			j++;
		}
	}
	for (int i = 1; i <= m; i++){
		printf("%d ", sum[i]);
	}
	return 0;
}
