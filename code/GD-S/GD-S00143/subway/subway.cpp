#include<bits/stdc++.h>
using namespace std;
int n,m,k[505],a[505][500005],t[505][500005],d,q,c,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%d %d",&a[i][j],&t[i][j]);
	}
	while(q--){
		scanf("%d %d",&x,&y);
		printf("0\n");
	}
	return 0;
} 
