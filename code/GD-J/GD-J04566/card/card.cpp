#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n, m, a[N], b[N], f[N], r[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		b[a[i]]=i, r[a[i]]++;
	}
	for(int i=1; i<=m; i++){
		int j=b[i];
		while(j<=n){
			f[a[j]]+=r[a[b[i]]];
			j=b[a[j]]+1;
		}
	}
	for(int i=1; i<=m; i++) printf("%d ", f[i]);
	return 0;
} 
