#include <bits/stdc++.h>
using namespace std;
#define N 200050
int i, j, k, n, m, a[N], f[N], p, l, c[N], u[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	for(i=1; i<=n; i++){
		for(j=i; j<=n; j++){
			f[++k]=a[j];
			if(c[a[j]]==0) c[a[j]]=j;
			else {
				for(l=c[a[j]]+1; l<=k; l++){
					c[f[l]]=0;
					f[l]=0;
				}
				k=c[a[j]];
			}
		}
		for(l=1; l<=k; l++){
			u[f[l]]++;
			printf("%d ", f[l]);
		}
		printf("\n");
		for(j=1; j<=m; j++){
			c[j]=0;
		}
		k=0;
	}
	for(i=1; i<=m; i++){
		printf("%d ", u[i]);	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
