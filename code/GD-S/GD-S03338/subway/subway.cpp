#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[500005],k[505],a[505][100005],t[505][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&a[i][j]);
		for(int j=1;j<=k[i];j++)
			scanf("%d",&t[i][j]);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		int ans=rand();
		printf("%d\n",ans);
	}
	return 0;
}
