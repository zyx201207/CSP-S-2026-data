#include<bits/stdc++.h>
using namespace std;
int c,s,e,n,m,d,q,w[500005],a[505][500005],x[505][500005];
long long ans=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for(int j=1;j<=a[i][0];j++){
			scanf("%d",&x[i][j]);
			scanf("%d",&a[i][x[i][j]]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&s,&e);
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
