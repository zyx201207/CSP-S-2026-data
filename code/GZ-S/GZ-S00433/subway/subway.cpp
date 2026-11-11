//GZ-S00433 遵义市南白中学 辜煜祺
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005],k[501],a[50005],t[50005],l[2];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
		scanf("%d ",&w[i]);
	for(int i=1; i<=n; i++) {
		scanf("%d",k[i]);
		for(int j=1; j<=k[i]; j++) {
			scanf("%d %d",&a[j],&k[j]);
		}
	}
	for(int i=1; i<=q; i++) {
		scanf("%d %d",&l[0],&l[1]);
		printf("%d",w[l[0]]+w[l[1]]+a[l[0]]+a[l[1]]);
	}
	fclose(stdin);
	fclose(stdout);
}

