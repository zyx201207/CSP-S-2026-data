#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, ne[N], count1[M], a[N], pos[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		ne[pos[a[i]]] = i;
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++){
			while(ne[j]) j = ne[j];
			count1[a[j]]++;
		}
	for(int i = 1; i <= m; i++) printf("%d ", count1[i]); 
	return 0;
}
