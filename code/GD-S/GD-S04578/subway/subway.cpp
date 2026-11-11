#include <bits/stdc++.h>
using namespace std;
int c,m,n,d,q,w[500005],k[505],a[505][1005],t[505][1005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>m>>n>>d>>q;
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=2*k[i];j++){
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][j]);
		}
	}
	while (q--){
		scanf("%d%d",&x,&y);

	}
	return 0;
}
